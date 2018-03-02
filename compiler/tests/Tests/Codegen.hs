-- Copyright (c) Microsoft. All rights reserved.
-- Licensed under the MIT license. See LICENSE file in the project root for full license information.

{-# LANGUAGE RecordWildCards #-}
{-# OPTIONS_GHC -fno-warn-incomplete-patterns #-}

module Tests.Codegen
    ( verifyCodegen
    , verifyCppCodegen
    , verifyCppCommCodegen
    , verifyCppGrpcCodegen
    , verifyApplyCodegen
    , verifyExportsCodegen
    , verifyCsCodegen
    , verifyCsCommCodegen
    , verifyJavaCodegen
    ) where

import System.FilePath
import Control.Monad
import Data.Monoid
import Data.Maybe
import Prelude
import Data.Algorithm.DiffContext
import Data.Text.Lazy (Text, unpack)
import qualified Data.Text.Lazy as LT
import qualified Data.ByteString.Char8 as BS
import Text.PrettyPrint (render, text)
import Test.Tasty
import Test.Tasty.Golden.Advanced
import Language.Bond.Codegen.Templates
import Language.Bond.Codegen.TypeMapping
import Language.Bond.Syntax.Types (Bond(..), Import, Declaration(..))
import Options
import IO

type Template = MappingContext -> String -> [Import] -> [Declaration] -> (String, Text)

verifyCppCodegen :: FilePath -> TestTree
verifyCppCodegen = verifyCodegen ["c++"]

verifyCsCodegen :: FilePath -> TestTree
verifyCsCodegen = verifyCodegen ["c#"]

verifyJavaCodegen :: FilePath -> TestTree
verifyJavaCodegen = verifyCodegen ["java"]

verifyCodegen :: [String] -> FilePath -> TestTree
verifyCodegen args baseName =
    testGroup baseName $
        verifyFiles (processOptions args) baseName

verifyApplyCodegen :: [String] -> FilePath -> TestTree
verifyApplyCodegen args baseName =
    testGroup baseName $
        map (verifyFile options baseName cppTypeMapping "apply") templates
  where
    options = processOptions args
    templates =
        [ apply_h protocols (export_attribute options) (allocator options) (template_alloc_enabled options)
        , apply_cpp protocols (allocator options) (template_alloc_enabled options)
        ]
    protocols =
        [ ProtocolReader "bond::CompactBinaryReader<bond::InputBuffer>"
        , ProtocolWriter "bond::CompactBinaryWriter<bond::OutputBuffer>"
        , ProtocolWriter "bond::CompactBinaryWriter<bond::OutputCounter>"
        , ProtocolReader "bond::FastBinaryReader<bond::InputBuffer>"
        , ProtocolWriter "bond::FastBinaryWriter<bond::OutputBuffer>"
        , ProtocolReader "bond::SimpleBinaryReader<bond::InputBuffer>"
        , ProtocolWriter "bond::SimpleBinaryWriter<bond::OutputBuffer>"
        ]

verifyExportsCodegen :: [String] -> FilePath -> TestTree
verifyExportsCodegen args baseName =
    testGroup baseName $
        map (verifyFile options baseName (cppExpandAliases (type_aliases_enabled options) cppTypeMapping) "exports") templates
  where
    options = processOptions args
    templates =
        [ reflection_h (export_attribute options) (allocator options) (template_alloc_enabled options)
        , comm_h (export_attribute options) (allocator options) (template_alloc_enabled options)
        ]

verifyCppCommCodegen :: [String] -> FilePath -> TestTree
verifyCppCommCodegen args baseName =
    testGroup baseName $
        map (verifyFile options baseName (cppExpandAliases (type_aliases_enabled options) cppTypeMapping) "") templates
  where
    options = processOptions args
    templates =
        [ comm_h (export_attribute options) (allocator options) (template_alloc_enabled options)
        , comm_cpp (template_alloc_enabled options)
        , types_cpp (template_alloc_enabled options)
        ]

verifyCppGrpcCodegen :: [String] -> FilePath -> TestTree
verifyCppGrpcCodegen args baseName =
    testGroup baseName $
        map (verifyFile options baseName (cppExpandAliases (type_aliases_enabled options) cppTypeMapping) "") templates
  where
    options = processOptions args
    templates =
        [ grpc_h (export_attribute options) (allocator options) (template_alloc_enabled options)
        , grpc_cpp (template_alloc_enabled options)
        , types_cpp (template_alloc_enabled options)
        ]

verifyCsCommCodegen :: [String] -> FilePath -> TestTree
verifyCsCommCodegen args baseName =
    testGroup baseName $
        map (verifyFile (processOptions args) baseName csTypeMapping "")
            [ comm_interface_cs
            , comm_proxy_cs
            , comm_service_cs
            , grpc_cs
            , types_cs Class (fieldMapping (processOptions args))
            ]
  where
    fieldMapping Cs {..} = if readonly_properties
        then ReadOnlyProperties
        else if fields
             then PublicFields
             else Properties

verifyFiles :: Options -> FilePath -> [TestTree]
verifyFiles options baseName =
    map (verify (typeMapping options) "") (templates options)
    <>
    extra options
  where
    verify = verifyFile options baseName
    fieldMapping Cs {..} = if readonly_properties
        then ReadOnlyProperties
        else if fields
             then PublicFields
             else Properties
    typeMapping Cpp {..} = cppExpandAliases type_aliases_enabled $ tm
        where
            allocatorType = if template_alloc_enabled then Just "_Alloc" else allocator
            typeMappingAliases = maybe cppTypeMapping (cppCustomAllocTypeMapping scoped_alloc_enabled template_alloc_enabled)  allocatorType 
            tm = if type_aliases_enabled then typeMappingAliases else cppExpandAliasesTypeMapping typeMappingAliases

    typeMapping Cs {} = csTypeMapping
    typeMapping Java {} = javaTypeMapping
    templates Cpp {..} =
        [ (reflection_h export_attribute allocator template_alloc_enabled)
        , (types_cpp template_alloc_enabled)
        , (comm_cpp template_alloc_enabled)
        , types_h header enum_header allocator alloc_ctors_enabled type_aliases_enabled scoped_alloc_enabled template_alloc_enabled
        ] <>
        [ enum_h | enum_header]
    templates Cs {..} =
        [ types_cs Class $ fieldMapping options
        ]
    templates Java {} =
        [ javaCatTemplate
        ]
    extra Cs {} =
        [ testGroup "collection interfaces" $
            map (verify csCollectionInterfacesTypeMapping "collection-interfaces") (templates options)
        ]
    extra Cpp {..} =
        [ testGroup "custom allocator" $
            map (verify (cppExpandAliasesTypeMapping $ cppCustomAllocTypeMapping False False "arena") "allocator")
                (templates $ options { allocator = Just "arena" })
            | isNothing allocator
        ] ++
        [ testGroup "constructors with allocator argument" $
            map (verify (cppExpandAliasesTypeMapping $ cppCustomAllocTypeMapping False False "arena") "alloc_ctors")
                (templates $ options { allocator = Just "arena", alloc_ctors_enabled = True })
            | isNothing allocator
        ] ++
        [ testGroup "type aliases" $
            map (verify (cppCustomAllocTypeMapping False False "arena") "type_aliases")
                (templates $ options { allocator = Just "arena", type_aliases_enabled = True })
        ] ++
        [ testGroup "scoped allocator" $
            map (verify (cppExpandAliasesTypeMapping $ cppCustomAllocTypeMapping True False "arena") "scoped_allocator")
                (templates $ options { allocator = Just "arena", scoped_alloc_enabled = True })
            | isNothing allocator
        ] ++
        [ testGroup "allocator concept no default allocator provided" $
            map (verify (cppExpandAliasesTypeMapping $ cppCustomAllocTypeMapping False True "_Alloc") "template_alloc_enabled_no_default")
                (templates $ options { template_alloc_enabled = True })
            | isNothing allocator
        ] ++
        [ testGroup "allocator concept with scoped allocator" $
            map (verify (cppExpandAliasesTypeMapping $ cppCustomAllocTypeMapping True False "_Alloc") "template_alloc_enabled_with_scoped_allocator")
                (templates $ options { scoped_alloc_enabled = True, template_alloc_enabled = True })
            | isNothing allocator
        ] ++
        [ testGroup "allocator concept default is allocator provided" $
            map (verify (cppExpandAliasesTypeMapping $ cppCustomAllocTypeMapping True False "_Alloc") "template_alloc_enabled_with_default")
                (templates $ options { allocator = Just "arena", template_alloc_enabled = True })
            | isNothing allocator
        ]
    extra Java {} =
        [
        ]

verifyFile :: Options -> FilePath -> TypeMapping -> FilePath -> Template -> TestTree
verifyFile options baseName typeMapping subfolder template =
    goldenTest suffix readGolden codegen cmp updateGolden
  where
    (suffix, _) = template (MappingContext typeMapping [] [] []) "" [] []
    golden = "tests" </> "generated" </> subfolder </> baseName ++ suffix
    readGolden = BS.readFile golden
    updateGolden = BS.writeFile golden
    codegen = do
        aliasMapping <- parseAliasMappings $ using options
        namespaceMapping <- parseNamespaceMappings $ namespace options
        (Bond imports namespaces declarations) <- parseBondFile [] $ "tests" </> "schema" </> baseName <.> "bond"
        let mappingContext = MappingContext typeMapping aliasMapping namespaceMapping namespaces
        let (_, code) = template mappingContext baseName imports declarations
        return $ BS.pack $ unpack code
    cmp x y = return $ if x == y then Nothing else Just $ diff x y
    diff x y = render $ prettyContextDiff
                            (text golden)
                            (text "test output")
                            (text . BS.unpack)
                            (getContextDiff 3 (BS.lines x) (BS.lines y))

javaCatTemplate :: MappingContext -> String -> [Import] -> [Declaration] -> (String, Text)
javaCatTemplate mappingContext _ imports declarations =
  (suffix, LT.concat $ mapMaybe codegenDecl declarations)
    where
      suffix = "_concatenated.java"
      codegenDecl declaration =
        case declaration of
          Struct {} -> Just $ class_java mappingContext imports declaration
          Enum {}   -> Just $ enum_java mappingContext declaration
          _         -> Nothing

cppExpandAliases :: Bool -> TypeMapping -> TypeMapping
cppExpandAliases type_aliases_enabled = if type_aliases_enabled
    then id
    else cppExpandAliasesTypeMapping
