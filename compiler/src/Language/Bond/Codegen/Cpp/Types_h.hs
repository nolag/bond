-- Copyright (c) Microsoft. All rights reserved.
-- Licensed under the MIT license. See LICENSE file in the project root for full license information.

{-# LANGUAGE QuasiQuotes, OverloadedStrings, RecordWildCards #-}

module Language.Bond.Codegen.Cpp.Types_h (types_h) where

import System.FilePath
import Data.Maybe
import Data.Monoid
import Prelude
import Numeric
import Data.Text.Lazy.Builder
import qualified Data.Text.Lazy as L
import qualified Data.Foldable as F
import Text.Shakespeare.Text
import Paths_bond (version)
import Data.Version
import Language.Bond.Syntax.Types
import Language.Bond.Syntax.Util
import Language.Bond.Syntax.Internal
import Language.Bond.Util
import Language.Bond.Codegen.TypeMapping
import Language.Bond.Codegen.Util
import qualified Language.Bond.Codegen.Cpp.Util as CPP

-- | Codegen template for generating /base_name/_type.h containing definitions
-- of C++ types representing the schema.
types_h :: [String]     -- ^ list of optional header files to be @#include@'ed by the generated code
        -> Bool         -- ^ 'True' to generate enum definitions into a separate file /base_name/_enum.h
        -> Maybe String -- ^ optional custom allocator to be used in the generated code
        -> Bool         -- ^ 'True' to generate constructors with allocator
        -> Bool         -- ^ 'True' to generate type aliases
        -> Bool         -- ^ 'True' to use std::scoped_allocator_adaptor for strings and containers
        -> Bool         -- ^ 'True' to use use the allocator concept in the generated type
        -> MappingContext -> String -> [Import] -> [Declaration] -> (String, L.Text)
types_h userHeaders enumHeader allocator alloc_ctors_enabled type_aliases_enabled scoped_alloc_enabled allocator_concept cpp file imports declarations = ("_types.h", [lt|
#pragma once
#{newlineBeginSep 0 includeHeader userHeaders}
#include <bond/core/bond_version.h>

#if BOND_VERSION < 0x0700
#error This file was generated by a newer version of the Bond compiler and is incompatible with your version of the Bond library.
#endif

#if BOND_MIN_CODEGEN_VERSION > 0x#{hexVersion version}
#error This file was generated by an older version of the Bond compiler and is incompatible with your version of the Bond library.
#endif

#include <bond/core/config.h>
#include <bond/core/containers.h>
#{newlineSep 0 optionalHeader bondHeaders}
#{memoryInclude}
#{includeEnum}
#{newlineSepEnd 0 includeImport imports}
#{CPP.openNamespace cpp}
    #{doubleLineSepEnd 1 id $ catMaybes $ aliasDeclarations}#{doubleLineSep 1 typeDeclaration declarations}
#{CPP.closeNamespace cpp}
#{optional usesAllocatorSpecialization allocationMadeWith }

|])
  where
    allocatorTemplateName = CPP.allocatorTemplateName allocator_concept
    allocatorDefaultType = CPP.defaultAllocator allocator_concept allocator
    allocatorTypeName = if allocator_concept then CPP.allocatorTypeName allocator_concept else allocator
    allocationMadeWith = if allocator_concept then allocatorTemplateName else allocator

    aliasDeclarations = if type_aliases_enabled then map aliasDeclName declarations else []
    aliasDeclName a@Alias {..} = Just [lt|#{CPP.template a False allocatorTemplateName}using #{declName} = #{getAliasDeclTypeName cpp a};|]
    aliasDeclName _ = Nothing

    hexVersion (Version xs _) = foldr showHex "" xs
    cppType = getTypeName cpp

    cppExpandAliases = if type_aliases_enabled then cpp { typeMapping = cppExpandAliasesTypeMapping $ typeMapping cpp } else cpp
    cppTypeExpandAliases = getTypeName cppExpandAliases

    idl = MappingContext idlTypeMapping [] [] []

    cppDefaultValue = CPP.defaultValue cpp

    includeImport (Import path) = [lt|#include "#{dropExtension path}_types.h"|]

    optionalHeader (False, _) = mempty
    optionalHeader (True, header) = includeHeader header

    includeHeader header = [lt|#include #{header}|]

    includeEnum = if enumHeader then [lt|#include "#{file}_enum.h"|] else mempty
    
    memoryInclude = if allocator_concept then [lt|#include <memory>|] else mempty

    -- True if declarations have any type satisfying f
    have f = getAny $ F.foldMap g declarations
      where
        g Struct{..} = F.foldMap (foldMapType f . fieldType) structFields
                    <> optional (foldMapType f) structBase
        g _ = mempty

    anyBonded (BT_Bonded _) = Any True
    anyBonded _ = Any False

    anyBlob BT_Blob = Any True
    anyBlob _ = Any False

    anyNullable = Any . isNullable

    anyStringOrContainer f = Any (isString f || isMetaName f || isContainer f)

    bondHeaders :: [(Bool, String)]
    bondHeaders = [
        (have anyNullable, "<bond/core/nullable.h>"),
        (have anyBonded, "<bond/core/bonded.h>"),
        (have anyBlob, "<bond/core/blob.h>"),
        (scoped_alloc_enabled && have anyStringOrContainer, "<scoped_allocator>")]

    usesAllocatorSpecialization alloc = [lt|
namespace std
{
    #{doubleLineSep 1 (usesAllocator allocator_concept) declarations}
}
|]
      where
        usesAllocator False s@Struct {..} = [lt|template <typename _Alloc#{sepBeginBy ", typename " paramName declParams}>
        struct uses_allocator<#{typename} #{getDeclTypeName cpp s}#{classParams}, _Alloc>
        : is_convertible<_Alloc, #{allocParam}>
    {};|]
            where
                typename = if null declParams then mempty else [lt|typename|]
                allocParam = if last alloc == '>' then alloc ++ " " else alloc
                classParams = CPP.classParams s allocatorTemplateName

        usesAllocator True s@Struct {..} = [lt|template<template<typename> typename #{alloc}, template<typename> typename _Alloc2>
        struct uses_allocator<#{getDeclTypeName cpp s}#{classParams}, _Alloc2>
        : is_convertible<#{alloc}<#{getDeclTypeName cpp s}#{classParams}>, _Alloc2<#{getDeclTypeName cpp s}#{classParams}>>
    {};|]
            where
                classParams = CPP.classParams s allocatorTemplateName

        usesAllocator _ _ = mempty

    -- forward declaration
    typeDeclaration f@Forward {..} = [lt|#{CPP.template f False allocatorTemplateName}struct #{declName};|]

    -- struct definition
    typeDeclaration s@Struct {..} = [lt|
    #{template}struct #{declName}#{optional base structBase}
    {
        #{thisTypesAllocator}
        #{newlineSepEnd 2 field structFields}#{defaultCtor}
        #{copyCtor}#{ifThenElse alloc_ctors_enabled (optional allocatorCopyCtor allocatorTypeName) mempty}
        #{moveCtor}#{ifThenElse alloc_ctors_enabled (optional allocatorMoveCtor allocatorTypeName) mempty}
        #{optional allocatorCtor allocatorTypeName}
        #{assignmentOp}

        bool operator==(const #{declName}&#{otherParam}) const
        {
            return true#{optional baseEqual structBase}#{newlineBeginSep 4 fieldEqual structFields};
        }

        bool operator!=(const #{declName}& #{otherParamName}) const
        {
            return !(*this == #{otherParamName});
        }

        void swap(#{declName}&#{otherParam})
        {
            using std::swap;#{optional swapBase structBase}#{newlineBeginSep 3 swapField structFields}
        }

        struct Schema;

    protected:
        #{initMetadata}
    };

    #{template}inline void swap(#{qualifiedClassName}& #{leftParamName}, #{qualifiedClassName}& #{rightParamName})
    {
        #{leftParamName}.swap(#{rightParamName});
    }|]
      where
        qualifiedClassName = CPP.qualifiedClassName cpp s allocatorTemplateName
        thisTypesAllocator = if allocator_concept then [lt|typedef _Alloc<#{CPP.className s allocatorTemplateName}> _TAlloc;|] else mempty;
        template = CPP.template s True allocatorDefaultType

        fieldNames :: [String]
        fieldNames = foldMapStructFields (return . fieldName) s

        otherParamName = uniqueName "other" fieldNames
        otherParam = if hasOnlyMetaFields then mempty else ' ':otherParamName
        hasOnlyMetaFields = not (any (not . getAny . metaField) structFields) && isNothing structBase
        hasMetaFields = getAny $ foldMapStructFields metaField s

        base x = [lt|
      : #{cppType x}|]

        field Field {..} = [lt|#{cppType fieldType} #{fieldName};|]

        notMeta Field {fieldType = BT_MetaName, ..} _ = [lt|/* skip bond_meta::name field '#{fieldName}' */|]
        notMeta Field {fieldType = BT_MetaFullName, ..} _ = [lt|/* skip bond_meta::full_name field '#{fieldName}' */|]
        notMeta _ f = f

        fieldEqual f@Field {..} = notMeta f [lt|&& (#{fieldName} ==#{otherParam}.#{fieldName})|]

        baseEqual b = [lt|
                && (static_cast<const #{cppType b}&>(*this) == static_cast<const #{cppType b}&>(#{otherParam}))|]

        swapField f@Field {..} = notMeta f [lt|swap(#{fieldName},#{otherParam}.#{fieldName});|]

        swapBase b = [lt|
            #{cppType b}::swap(#{otherParam});|]

        -- value to pass to field initializer in ctor initialize list
        -- or Nothing if field doesn't need explicit initialization
        initValue (BT_Maybe _) _ = Nothing
        initValue t (Just d) = Just $ cppDefaultValue t d
        initValue (BT_TypeParam _) _ = Just mempty
        initValue (BT_UserDefined a@Alias {} args) d
            | customAliasMapping cpp a = Just mempty
            | otherwise = initValue (resolveAlias a args) d
        initValue t _
            | isScalar t = Just mempty
            | otherwise = Nothing

        -- constructor initializer list from 'base' and 'fields' initializers
        initializeList base' fields = between colon mempty $ commaLineSep 3 id [base', fields]
          where
            colon = [lt|
          : |]

        -- constructor body
        ctorBody = if hasMetaFields then [lt|
        {
            InitMetadata("#{declName}", "#{getDeclTypeName idl s}");
        }|]
            else [lt|
        {
        }|]

        needAlloc alloc = isJust structBase || any (allocParameterized alloc . fieldType) structFields
        
        allocParameterized alloc t = (isStruct t) || (L.isInfixOf (L.pack alloc) $ toLazyText $ cppTypeExpandAliases t)

        -- default constructor
        defaultCtor = [lt|
        #{dummyTemplateTag}#{declName}(#{vc12WorkaroundParam})#{initList}#{ctorBody}|]
          where
            needAllocParam = maybe False needAlloc allocationMadeWith

            vc12WorkaroundParam = if needAllocParam then [lt|_bond_vc12_ctor_workaround_ = {}|] else mempty

            dummyTemplateTag = if needAllocParam
                then [lt|struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        |]
                else mempty

            initList = initializeList mempty
                $ commaLineSep 3 fieldInit structFields
            fieldInit Field {..} = optional (\x -> [lt|#{fieldName}(#{x})|])
                $ initValue fieldType fieldDefault

        allocatorCtor alloc = [lt|
        explicit
        #{declName}(const #{alloc}&#{allocParam})#{initList}#{ctorBody}
        |]
          where
            allocParam = if needAlloc alloc then [lt| allocator|] else mempty
            initList = initializeList
                (optional baseInit structBase)
                (commaLineSep 3 fieldInit structFields)
            baseInit b = [lt|#{cppType b}(allocator)|]
            fieldInit Field {..} = optional (\x -> [lt|#{fieldName}(#{x})|])
                $ allocInitValue fieldType fieldDefault
            allocInitValue t@(BT_UserDefined a@Alias {} args) d
                | allocParameterized alloc t = allocInitValue (resolveAlias a args) d
                | otherwise = initValue t d
            allocInitValue (BT_Nullable t) _ = allocInitValue t Nothing
            allocInitValue (BT_Maybe t) _ = allocInitValue t Nothing
            allocInitValue t (Just d)
                | isString t = Just [lt|#{cppDefaultValue t d}, allocator|]
            allocInitValue t Nothing
                | isContainer t || isMetaName t || isString t || isStruct t = Just "allocator"
            allocInitValue t d = initValue t d

        -- copy constructor
        copyCtor = if hasMetaFields then define else implicitlyDeclared
          where
            -- default OK when there are no meta fields
            implicitlyDeclared = [lt|
        // Compiler generated copy ctor OK
        #{declName}(const #{declName}&) = default;|]

            -- define ctor to initialize meta fields
            define = [lt|#{declName}(const #{declName}& #{otherParamName})#{initList}#{ctorBody}|]
              where
                initList = initializeList
                    (optional baseCopy structBase)
                    (commaLineSep 3 fieldCopy structFields)
                baseCopy b = [lt|#{cppType b}(#{otherParamName})|]
                fieldCopy Field {..} = [lt|#{fieldName}(#{otherParamName}.#{fieldName}#{getAllocator fieldType})|]
                getAllocator BT_MetaName = [lt|.get_allocator()|]
                getAllocator BT_MetaFullName =  [lt|.get_allocator()|]
                getAllocator _ = mempty

        -- copy/move constructor with allocator
        allocatorCopyOrMoveCtor otherParamDecl otherParamValue alloc = [lt|

        #{declName}(#{otherParamDecl declName}#{otherParam}, const #{alloc}&#{allocParam})#{initList}#{ctorBody}|]
          where
            allocParam = if needAlloc alloc then [lt| allocator|] else mempty

            initList = initializeList
                (optional baseInit structBase)
                (commaLineSep 3 fieldInit structFields)
            baseInit b = [lt|#{cppType b}(#{otherParamValue $ L.pack otherParamName}, allocator)|]

            fieldRef fieldName = [lt|#{otherParamName}.#{fieldName}|]
            fieldInit Field {..} = [lt|#{fieldName}(#{otherParamValue $ fieldRef fieldName}#{allocInitValueText fieldType})|]

            allocInitValueText fieldType = optional (\x -> [lt|, #{x}|])
                $ allocInitValue fieldType
            allocInitValue t@(BT_UserDefined a@Alias {} args)
                | allocParameterized alloc t = allocInitValue (resolveAlias a args)
                | otherwise = Nothing
            allocInitValue (BT_Nullable t) = allocInitValue t
            allocInitValue (BT_Maybe t) = allocInitValue t
            allocInitValue t
                | isList t || isMetaName t || isString t || isStruct t || isAssociative t = Just [lt|allocator|]
                | otherwise = Nothing

        -- copy constructor with allocator
        allocatorCopyCtor alloc = allocatorCopyOrMoveCtor (\f -> [lt|const #{f}&|]) id alloc

        -- move constructor
        moveCtor = if hasMetaFields then [lt|
        #{explicit}|]
            -- even if implicit would be okay, fall back to explicit for
            -- compilers that don't support = default for move constructors
                                    else [lt|
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        #{explicit}
#else
        #{implicit}
#endif|]
          where
            -- default OK when there are no meta fields
            implicit = [lt|#{declName}(#{declName}&&) = default;|]

            -- define ctor to perform member-by-member move and--if
            -- needed--initialize meta fields
            explicit = [lt|#{declName}(#{declName}&&#{param})#{initList}#{ctorBody}|]
            initList = initializeList
                (optional baseMove structBase)
                (commaLineSep 3 fieldMove structFields)
            baseMove b = [lt|#{cppType b}(std::move(#{otherParamName}))|]
            fieldMove Field {..} = [lt|#{fieldName}(std::move(#{otherParamName}.#{fieldName}))|]
            param = if initList == mempty then mempty else ' ':otherParamName

        -- move constructor with allocator
        allocatorMoveCtor alloc = (allocatorCopyOrMoveCtor (\f -> [lt|#{f}&&|]) (\f -> [lt|std::move(#{f})|]) alloc)

        -- operator=
        assignmentOp = if hasMetaFields then define else implicitlyDeclared
          where
            -- default OK when there are no meta fields
            implicitlyDeclared = [lt|
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        #{define}
#else
        // Compiler generated operator= OK
        #{declName}& operator=(const #{declName}&) = default;
        #{declName}& operator=(#{declName}&&) = default;
#endif|]

            -- define operator= using swap
            define = [lt|#{declName}& operator=(#{declName} #{otherParamName})
        {
            #{otherParamName}.swap(*this);
            return *this;
        }|]

        initMetadata = [lt|void InitMetadata(const char*#{nameParam}, const char*#{qualifiedNameParam})
        {#{newlineBeginSep 3 id [baseInit, nameInit, qualifiedInit]}
        }|]
          where
            nameParam = if baseInit == mempty && nameInit == mempty then mempty else uniqueName "name" fieldNames
            qualifiedNameParam = if baseInit == mempty && qualifiedInit == mempty then mempty else uniqueName "qual_name" fieldNames
            baseInit = optional (\b -> [lt|#{cppType b}::InitMetadata(#{nameParam}, #{qualifiedNameParam});|]) structBase
            nameInit = newlineSep 3 init' structFields
              where
                init' Field {fieldType = BT_MetaName, ..} = [lt|this->#{fieldName} = #{nameParam};|]
                init' _ = mempty
            qualifiedInit = newlineSep 3 init' structFields
              where
                init' Field {fieldType = BT_MetaFullName, ..} = [lt|this->#{fieldName} = #{qualifiedNameParam};|]
                init' _ = mempty

        leftParamName = uniqueName "left" fieldNames
        rightParamName = uniqueName "right" fieldNames

    -- enum definition and helpers
    typeDeclaration e@Enum {..} = [lt|
    namespace _bond_enumerators
    {
    namespace #{declName}
    {
        #{enumDefinition}
        inline BOND_CONSTEXPR const char* GetTypeName(enum #{declName})
        {
            return "#{declName}";
        }

        inline BOND_CONSTEXPR const char* GetTypeName(enum #{declName}, const ::bond::qualified_name_tag&)
        {
            return "#{getDeclTypeName idl e}";
        }

#if defined(_MSC_VER) && (_MSC_VER < 1900) // Versions of MSVC prior to 1900 do not support magic statics
        extern const std::map<enum #{declName}, std::string> _value_to_name_#{declName};

        inline const std::map<enum #{declName}, std::string>& GetValueToNameMap(enum #{declName})
        {
            return _value_to_name_#{declName};
        }

        extern const std::map<std::string, enum #{declName}> _name_to_value_#{declName};

        inline const std::map<std::string, enum #{declName}>& GetNameToValueMap(enum #{declName})
        {
            return _name_to_value_#{declName};
        }
#else
        template <typename Map = std::map<enum #{declName}, std::string> >
        inline const Map& GetValueToNameMap(enum #{declName}, ::bond::detail::mpl::identity<Map> = {})
        {
            static const Map s_valueToNameMap
                {
                    #{CPP.enumValueToNameInitList 5 e}
                };
            return s_valueToNameMap;
        }

        template <typename Map = std::map<std::string, enum #{declName}> >
        inline const Map& GetNameToValueMap(enum #{declName}, ::bond::detail::mpl::identity<Map> = {})
        {
            static const Map s_nameToValueMap
                {
                    #{CPP.enumNameToValueInitList 5 e}
                };
            return s_nameToValueMap;
        }
#endif
        const std::string& ToString(enum #{declName} value);

        void FromString(const std::string& name, enum #{declName}& value);

        bool ToEnum(enum #{declName}& value, const std::string& name);

        bool FromEnum(std::string& name, enum #{declName} value);

    } // namespace #{declName}
    } // namespace _bond_enumerators

    #{enumUsing}|]
      where
        enumDefinition = if enumHeader then mempty else [lt|#{CPP.enumDefinition e}
        |]
        enumUsing = if enumHeader then mempty else [lt|using namespace _bond_enumerators::#{declName};
    |]

    typeDeclaration _ = mempty
