-- Copyright (c) Microsoft. All rights reserved.
-- Licensed under the MIT license. See LICENSE file in the project root for full license information.

{-# LANGUAGE QuasiQuotes, OverloadedStrings, RecordWildCards #-}

module Language.Bond.Codegen.Cpp.ApplyOverloads (applyOverloads, Protocol(..)) where

import Data.Maybe
import Data.Monoid
import Prelude
import Data.Text.Lazy (Text)
import Text.Shakespeare.Text
import Language.Bond.Syntax.Types
import Language.Bond.Codegen.TypeMapping
import Language.Bond.Codegen.Util
import qualified Language.Bond.Codegen.Cpp.Util as CPP

-- | Protocol data type is used to specify what protocols the @Apply@ function
-- overloads should be generated for.
data Protocol =
    ProtocolReader String | -- ^ Name of the class implementing the protocol reader.
    ProtocolWriter String   -- ^ Name of the class implementing the protocol writer.


-- Apply overloads
applyOverloads :: [Protocol] -> MappingContext -> Text -> Text -> Maybe String -> Bool -> Declaration -> Text
applyOverloads protocols cpp attr extern allocator allocator_concept s@Struct {..} | null declParams = [lt|
    //
    // Extern template specializations of Apply function with common
    // transforms for #{declName}#{allocatorNote}.
    //

    #{extern}template #{attr}
    bool Apply(const ::bond::To< #{qualifiedName}>& transform,
               const ::bond::bonded< #{qualifiedName}>& value);

    #{extern}template #{attr}
    bool Apply(const ::bond::InitSchemaDef& transform,
               const #{qualifiedName}& value);

    #{extern}template #{attr}
    bool Apply(const ::bond::Null& transform,
               const ::bond::bonded< #{qualifiedName}, ::bond::SimpleBinaryReader< ::bond::InputBuffer>&>& value);
    #{newlineSep 1 applyOverloads' protocols}|]
  where
    defaultAllocator = CPP.defaultAllocator allocator_concept allocator
    qualifiedName = CPP.qualifiedClassName cpp s defaultAllocator
    allocatorNote = if allocator_concept then [lt| for the default allocator type, #{fromJust defaultAllocator}|] else mempty

    applyOverloads' p = [lt|#{deserialization p}#{newlineSep 1 (serialization p) serializingTransforms}|]

    serializingTransforms =
        [ [lt|Serializer|]
        , [lt|Marshaler|]
        ]

    deserialization (ProtocolWriter _) = mempty
    deserialization (ProtocolReader protocolReader) = [lt|
    #{extern}template #{attr}
    bool Apply(const ::bond::To< #{qualifiedName}>& transform,
               const ::bond::bonded< #{qualifiedName}, #{protocolReader}&>& value);

    #{extern}template #{attr}
    bool Apply(const ::bond::To< #{qualifiedName}>& transform,
               const ::bond::bonded<void, #{protocolReader}&>& value);|]

    serialization (ProtocolReader _) _ = mempty
    serialization (ProtocolWriter protocolWriter) transform = [lt|
    #{extern}template #{attr}
    bool Apply(const ::bond::#{transform}<#{protocolWriter} >& transform,
               const #{qualifiedName}& value);

    #{extern}template #{attr}
    bool Apply(const ::bond::#{transform}<#{protocolWriter} >& transform,
               const ::bond::bonded< #{qualifiedName}>& value);
    #{newlineSep 1 transcoding protocols}|]
      where
        transcoding (ProtocolWriter _) = mempty
        transcoding (ProtocolReader protocolReader) = [lt|
    #{extern}template #{attr}
    bool Apply(const ::bond::#{transform}<#{protocolWriter} >& transform,
               const ::bond::bonded< #{qualifiedName}, #{protocolReader}&>& value);|]

applyOverloads _ _ _ _ _ _ _ = mempty
