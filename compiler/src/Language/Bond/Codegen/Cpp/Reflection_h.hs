-- Copyright (c) Microsoft. All rights reserved.
-- Licensed under the MIT license. See LICENSE file in the project root for full license information.

{-# LANGUAGE QuasiQuotes, OverloadedStrings, RecordWildCards #-}

module Language.Bond.Codegen.Cpp.Reflection_h (reflection_h) where

import System.FilePath
import Data.Monoid
import Prelude
import Data.Text.Lazy (Text)
import qualified Data.Foldable as F
import Text.Shakespeare.Text
import Language.Bond.Util
import Language.Bond.Syntax.Types
import Language.Bond.Codegen.TypeMapping
import Language.Bond.Codegen.Util
import qualified Language.Bond.Codegen.Cpp.Util as CPP

-- | Codegen template for generating /base_name/_reflection.h containing schema
-- metadata definitions.
reflection_h :: Maybe String -> Maybe String -> Bool -> MappingContext -> String -> [Import] -> [Declaration] -> (String, Text)
reflection_h export_attribute allocator allocator_concept cpp file imports declarations = ("_reflection.h", [lt|
#pragma once

#include "#{file}_types.h"
#include <bond/core/reflection.h>
#{newlineSepEnd 0 include imports}
#{CPP.openNamespace cpp}
    #{doubleLineSepEnd 1 schema declarations}
#{CPP.closeNamespace cpp}
|])
  where
    idl = MappingContext idlTypeMapping [] [] []  

    -- C++ type
    cppType = getTypeName cpp

    -- template for generating #include statement from import
    include (Import path) = [lt|#include "#{dropExtension path}_reflection.h"|]

    -- template for generating struct schema
    schema s@Struct {..} = [lt|//
    // #{declName}
    //
    #{CPP.template s False allocatorDefaultType}struct #{className}::Schema
    {
        typedef #{baseType structBase} base;

        #{export_attr}static const ::bond::Metadata metadata;
        #{newlineBeginSep 2 fieldMetadata structFields}

        public: struct var
        {#{fieldTemplates structFields}};

        private: typedef boost::mpl::list<> fields0;
        #{newlineSep 2 pushField indexedFields}

        public: typedef #{typename}fields#{length structFields}::type fields;
        #{constructor}
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit#{metadataInitArgs}("#{declName}", "#{getDeclTypeName idl s}",
                #{CPP.attributeInit declAttributes}
            );
        }
    };
    #{onlyTemplate $ CPP.schemaMetadata cpp s allocatorTemplateName}|]
      where
        allocatorTemplateName = CPP.allocatorTemplateName allocator_concept
        allocatorDefaultType = CPP.defaultAllocator allocator_concept allocator

        -- The allocator template type should not be in the list as a template type
        classParams = CPP.classParams s Nothing
        className = CPP.className s allocatorTemplateName
        onlyTemplate = CPP.onlyTemplate declParams allocator_concept
        export_attr = CPP.onlyNonTemplate declParams allocator_concept $ optional (\a -> [lt|#{a}
        |]) export_attribute

        onlyParams = CPP.onlyTemplate declParams allocator_concept

        metadataInitArgs = if null declParams then mempty else [lt|<boost::mpl::list#{classParams} >|]

        typename = onlyParams [lt|typename |]

        -- constructor, generated only for struct templates
        constructor = onlyTemplate [lt|
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            #{newlineSep 3 static structFields}
        }|]
          where
            static Field {..} = [lt|(void)s_#{fieldName}_metadata;|]
        
        -- reversed list of field names zipped with indexes
        indexedFields :: [(String, Int)]
        indexedFields = zipWith ((,) . fieldName) (reverse structFields) [0..]

        baseType (Just base) = cppType base
        baseType Nothing = "::bond::no_base"

        pushField (field, i) =
            [lt|private: typedef #{typename}boost::mpl::push_front<fields#{i}, #{typename}var::#{field}>::type fields#{i + 1};|]

        fieldMetadata Field {..} =
            [lt|private: #{export_attr}static const ::bond::Metadata s_#{fieldName}_metadata;|]

        fieldTemplates = F.foldMap $ \ f@Field {..} -> [lt|
            // #{fieldName}
            typedef struct : ::bond::reflection::FieldTemplate<
                #{fieldOrdinal},
                #{CPP.modifierTag f},
                #{className},
                #{cppType fieldType},
                &#{className}::#{fieldName},
                &s_#{fieldName}_metadata
            > {}  #{fieldName};
        |]


    -- nothing to generate for enums
    schema _ = mempty
