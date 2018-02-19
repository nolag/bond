-- Copyright (c) Microsoft. All rights reserved.
-- Licensed under the MIT license. See LICENSE file in the project root for full license information.

{-# LANGUAGE QuasiQuotes, OverloadedStrings, RecordWildCards #-}

module Language.Bond.Codegen.Cpp.Comm_cpp (comm_cpp) where

import Data.Monoid
import Prelude
import Data.Text.Lazy (Text)
import Text.Shakespeare.Text
import Language.Bond.Syntax.Types
import Language.Bond.Codegen.TypeMapping
import Language.Bond.Codegen.Util
import qualified Language.Bond.Codegen.Cpp.Util as CPP

-- | Codegen template for generating /base_name/_comm.cpp containing
-- definitions of helper functions and schema metadata static variables.
comm_cpp :: Bool         -- ^ 'True' to use use the allocator concept in the generated type
    -> MappingContext -> String -> [Import] -> [Declaration] -> (String, Text)
comm_cpp allocator_concept cpp file _imports declarations = ("_comm.cpp", [lt|
#include "#{file}_reflection.h"
#include "#{file}_comm.h"

#{CPP.openNamespace cpp}
    #{doubleLineSepEnd 1 statics declarations}
#{CPP.closeNamespace cpp}
|])
  where
    -- definitions of Schema statics for non-generic services
    statics s@Service {..} =
        CPP.onlyNonTemplate declParams allocator_concept $ CPP.schemaMetadata cpp s Nothing

    statics _ = mempty
