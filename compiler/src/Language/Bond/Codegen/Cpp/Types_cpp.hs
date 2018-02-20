-- Copyright (c) Microsoft. All rights reserved.
-- Licensed under the MIT license. See LICENSE file in the project root for full license information.

{-# LANGUAGE QuasiQuotes, OverloadedStrings, RecordWildCards #-}

module Language.Bond.Codegen.Cpp.Types_cpp (types_cpp) where

import Data.Monoid
import Prelude
import Data.Text.Lazy (Text)
import Text.Shakespeare.Text
import Language.Bond.Syntax.Types
import Language.Bond.Codegen.TypeMapping
import Language.Bond.Codegen.Util
import qualified Language.Bond.Codegen.Cpp.Util as CPP

-- | Codegen template for generating /base_name/_types.cpp containing
-- definitions of helper functions and schema metadata static variables.
types_cpp :: Bool         -- ^ 'True' to use use the allocator concept in the generated type
    -> MappingContext -> String -> [Import] -> [Declaration] -> (String, Text)
types_cpp allocator_concept cpp file _imports declarations = ("_types.cpp", [lt|
#include "#{file}_reflection.h"
#include <bond/core/exception.h>
#{unorderedMapInclude}
#{CPP.openNamespace cpp}
    #{doubleLineSepEnd 1 statics declarations}
#{CPP.closeNamespace cpp}
|])
  where
    unorderedMapInclude = if not (any CPP.isEnumDeclaration declarations) then mempty else [lt|#include <unordered_map>
|]

    -- definitions of Schema statics for non-generic structs
    statics s@Struct {..} =
        if null declParams && not allocator_concept then CPP.schemaMetadata cpp s Nothing else mempty

    -- global variables for enum name/value conversions
    --
    -- ToString is intentionally not implemented in terms of FromEnum, as
    -- ToString returns a reference to the name stored in the map. FromEnum
    -- copies this name into the output paramater.
    statics e@Enum {..} = [lt|
    namespace _bond_enumerators
    {
    namespace #{declName}
    {
#if defined(_MSC_VER) && (_MSC_VER < 1900)
        const std::map<std::string, enum #{declName}> _name_to_value_#{declName}
            {
                #{CPP.enumNameToValueInitList 4 e}
            };

        const std::map<enum #{declName}, std::string> _value_to_name_#{declName}
            {
                #{CPP.enumValueToNameInitList 4 e}
            };
#else
        namespace
        {
            struct _hash_#{declName}
            {
                std::size_t operator()(enum #{declName} value) const
                {
                    return static_cast<std::size_t>(value);
                }
            };
        }
#endif
        const std::string& ToString(enum #{declName} value)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1900)
            const auto& map = GetValueToNameMap(value);
#else
            const auto& map = GetValueToNameMap<std::unordered_map<enum #{declName}, std::string, _hash_#{declName}> >(value);
#endif
            auto it = map.find(value);

            if (map.end() == it)
                ::bond::InvalidEnumValueException(value, "#{declName}");

            return it->second;
        }

        void FromString(const std::string& name, enum #{declName}& value)
        {
            if (!ToEnum(value, name))
                ::bond::InvalidEnumValueException(name.c_str(), "#{declName}");
        }

        bool ToEnum(enum #{declName}& value, const std::string& name)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1900)
            const auto& map = GetNameToValueMap(value);
#else
            const auto& map = GetNameToValueMap<std::unordered_map<std::string, enum #{declName}> >(value);
#endif
            auto it = map.find(name);

            if (map.end() == it)
                return false;

            value = it->second;

            return true;
        }

        bool FromEnum(std::string& name, enum #{declName} value)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1900)
            const auto& map = GetValueToNameMap(value);
#else
            const auto& map = GetValueToNameMap<std::unordered_map<enum #{declName}, std::string, _hash_#{declName}> >(value);
#endif
            auto it = map.find(value);

            if (map.end() == it)
                return false;

            name = it->second;

            return true;
        }

    } // namespace #{declName}
    } // namespace _bond_enumerators|]

    statics _ = mempty
