-- Copyright (c) Microsoft. All rights reserved.
-- Licensed under the MIT license. See LICENSE file in the project root for full license information.

{-# LANGUAGE QuasiQuotes, OverloadedStrings, RecordWildCards #-}
{-# OPTIONS_GHC -Wwarn #-}

module Language.Bond.Codegen.Cpp.Util
    ( openNamespace
    , closeNamespace
    , className
    , classParams
    , qualifiedClassName
    , template
    , modifierTag
    , defaultValue
    , attributeInit
    , schemaMetadata
    , enumDefinition
    , isEnumDeclaration
    , enumValueToNameInitList
    , enumNameToValueInitList
    , allocatorTemplateName
    , defaultAllocator
    , needsTemplate
    , onlyTemplate
    , onlyNonTemplate
    ) where

import Data.Int (Int64)
import Data.List (sortOn)
import Data.Monoid
import Prelude
import Data.Text.Lazy (Text, unpack)
import Data.Text.Lazy.Builder (toLazyText)
import Text.Shakespeare.Text
import Language.Bond.Syntax.Types
import Language.Bond.Syntax.Util
import Language.Bond.Util
import Language.Bond.Codegen.Util
import Language.Bond.Codegen.TypeMapping

-- open namespaces
openNamespace :: MappingContext -> Text
openNamespace cpp = newlineSep 0 open $ getNamespace cpp
  where
    open n = [lt|namespace #{n}
{|]

-- close namespaces in reverse order
closeNamespace :: MappingContext -> Text
closeNamespace cpp = newlineSep 0 close (reverse $ getNamespace cpp)
  where
    close n = [lt|} // namespace #{n}|]

className :: Declaration -> Maybe String -> String
className decl allocator = declName decl <> classParams decl allocator

classParamsRaw :: Declaration -> String
classParamsRaw = sepBy ", " paramName . declParams

classParams :: Declaration -> Maybe String -> String
classParams e@Enum {..} _ = classParams e Nothing
classParams d (Just []) = classParams d Nothing
classParams d (Just allocator) = angles $ ((classParamsRaw d) ++ optComma ++ allocator)
    where
        optComma = if null $ declParams d then "" else ", "
classParams d Nothing = angles $ classParamsRaw d

qualifiedClassName :: MappingContext -> Declaration -> Maybe String -> String
qualifiedClassName cpp s@Struct {..} allocator = qualifiedName <> classParams s allocator
  where
    qualifiedName = unpack $ toLazyText $ getDeclTypeName cpp s
qualifiedClassName _ _ _= error "qualifiedClassName: impossible happened."

templateParams :: Declaration -> String
templateParams d = if null $ declParams d then mempty else params
    where
        params = "typename " ++ (sepBy ", typename " paramName $ declParams d)


fillTemplateDefault :: Bool -> String -> Text
fillTemplateDefault _ [] = mempty
fillTemplateDefault True allocator =  [lt|=#{allocator}|]
fillTemplateDefault False _ = mempty

template :: Declaration -> Bool -> Maybe String -> Text
template d declared_here (Just allocator) =  [lt|template <#{templateParams d}#{optComma}class _Alloc#{fillTemplateDefault declared_here allocator}>
    |]
    where
        optComma = if null $ declParams d then mempty else [lt|, |]
template d _ Nothing = if null $ declParams d then mempty else [lt|template <#{templateParams d}>
    |]
    
-- attribute initializer
attributeInit :: [Attribute] -> Text
attributeInit [] = "::bond::reflection::Attributes()"
attributeInit xs = [lt|{
                    #{commaLineSep 5 attrNameValueText sortedAttributes}
                }|]
  where
    idl = MappingContext idlTypeMapping [] [] []
    attrNameValue Attribute {..} = (getQualifiedName idl attrName, attrValue)
    sortedAttributes = sortOn fst $ map attrNameValue xs
    attrNameValueText (name, value) = [lt|{ "#{name}", "#{value}" }|]


-- modifier tag type for a field
modifierTag :: Field -> Text
modifierTag Field {..} = [lt|::bond::reflection::#{modifier fieldType fieldModifier}_field_modifier|]
  where
    modifier BT_MetaName _ = [lt|required_optional|]
    modifier BT_MetaFullName _ = [lt|required_optional|]
    modifier _ RequiredOptional = [lt|required_optional|]
    modifier _ Required = [lt|required|]
    modifier _ _ = [lt|optional|]

defaultValue :: MappingContext -> Type -> Default -> Text
defaultValue _ BT_WString (DefaultString x) = [lt|L"#{x}"|]
defaultValue _ BT_String (DefaultString x) = [lt|"#{x}"|]
defaultValue _ BT_Float (DefaultFloat x) = [lt|#{x}f|]
defaultValue _ BT_Int64 (DefaultInteger (-9223372036854775808)) = [lt|-9223372036854775807LL-1|]
defaultValue _ BT_Int64 (DefaultInteger x) = [lt|#{x}LL|]
defaultValue _ BT_UInt64 (DefaultInteger x) = [lt|#{x}ULL|]
defaultValue _ BT_Int32 (DefaultInteger (-2147483648)) = [lt|-2147483647-1|]
defaultValue m t (DefaultEnum x) = enumValue m t x
defaultValue _ _ (DefaultBool True) = "true"
defaultValue _ _ (DefaultBool False) = "false"
defaultValue _ _ (DefaultInteger x) = [lt|#{x}|]
defaultValue _ _ (DefaultFloat x) = [lt|#{x}|]
defaultValue _ _ (DefaultNothing) = mempty
defaultValue m (BT_UserDefined a@Alias {..} args) d = defaultValue m (resolveAlias a args) d
defaultValue _ _ _ = error "defaultValue: impossible happened."

enumValue :: ToText a => MappingContext -> Type -> a -> Text
enumValue cpp (BT_UserDefined e@Enum {..} _) x =
    [lt|#{getQualifiedName cpp $ getDeclNamespace cpp e}::_bond_enumerators::#{declName}::#{x}|]
enumValue cpp (BT_UserDefined a@Alias {..} args) e = enumValue cpp (resolveAlias a args) e
enumValue _ _ _ = error "enumValue: impossible happened."

-- schema metadata static member definitions
schemaMetadata :: MappingContext -> Declaration -> Maybe String -> Text
schemaMetadata cpp s@Struct {..} allocator = [lt|
    #{template s False allocator}const ::bond::Metadata #{className s allocator}::Schema::metadata
        = #{className s allocator}::Schema::GetMetadata();#{newlineBeginSep 1 staticDef structFields}|]
  where
    -- static member definition for field metadata
    staticDef f@Field {..}
        | fieldModifier == Optional && null fieldAttributes = [lt|
    #{template s False allocator}const ::bond::Metadata #{className s allocator}::Schema::s_#{fieldName}_metadata
        = ::bond::reflection::MetadataInit(#{defaultInit f}"#{fieldName}");|]
        | otherwise = [lt|
    #{template s False allocator}const ::bond::Metadata #{className s allocator}::Schema::s_#{fieldName}_metadata
        = ::bond::reflection::MetadataInit(#{defaultInit f}"#{fieldName}", #{modifierTag f}::value,
                #{attributeInit fieldAttributes});|]
      where
        defaultInit Field {fieldDefault = (Just def)} = [lt|#{explicitDefault def}, |]
        defaultInit _ = mempty
        explicitDefault (DefaultNothing) = "::bond::nothing"
        explicitDefault d@(DefaultInteger _) = staticCast d
        explicitDefault d@(DefaultFloat _) = staticCast d
        explicitDefault d = defaultValue cpp fieldType d
        staticCast d = [lt|static_cast<#{getTypeName cpp fieldType}>(#{defaultValue cpp fieldType d})|]
schemaMetadata _ s@Service {..} allocator = [lt|
    #{template s False allocator}const ::bond::Metadata #{className s allocator}::Schema::metadata
        = ::bond::reflection::MetadataInit#{metadataInitArgs}("#{declName}", "#{idlNamespace}",
                #{attributeInit declAttributes});#{newlineBeginSep 1 staticDef serviceMethods}|]
  where
    idl = MappingContext idlTypeMapping [] [] []
    idlNamespace = getDeclTypeName idl s
    metadataInitArgs = if null declParams then mempty else [lt|<boost::mpl::list#{classParams s allocator} >|]
    -- static member definition for method metadata
    staticDef m = [lt|
    #{template s False allocator}const ::bond::Metadata #{className s allocator}::Schema::s_#{methodName m}_metadata
        = ::bond::reflection::MetadataInit("#{methodName m}"#{attributes $ methodAttributes m}|]
      where
        attributes [] = [lt|);|]
        attributes a = [lt|,
                #{attributeInit a});|]
schemaMetadata _ _ _ = error "schemaMetadata: impossible happened."

enumDefinition :: Declaration -> Text
enumDefinition Enum {..} = [lt|enum #{declName}
        {
            #{commaLineSep 3 constant enumConstants}
        };|]
  where
    constant Constant {..} = [lt|#{constantName}#{optional value constantValue}|]
    value (-2147483648) = [lt| = static_cast<int32_t>(-2147483647-1)|]
    value x = [lt| = static_cast<int32_t>(#{x})|]
enumDefinition _ = error "enumDefinition: impossible happened."

isEnumDeclaration :: Declaration -> Bool
isEnumDeclaration Enum {} = True
isEnumDeclaration _ = False


enumValueToNameInitList :: Int64 -> Declaration -> Text
enumValueToNameInitList n Enum {..} = commaLineSep n valueNameConst enumConstByValue
  where
    valueNameConst (name, _) = [lt|{ #{name}, "#{name}" }|]
    enumConstByValue = sortOn snd $ reifyEnumValues enumConstants
enumValueToNameInitList _ _ = error "enumValueToNameInitList: impossible happened."

enumNameToValueInitList :: Int64 -> Declaration -> Text
enumNameToValueInitList n Enum {..} = commaLineSep n nameValueConst enumConstByName
  where
    nameValueConst Constant {..} = [lt|{ "#{constantName}", #{constantName} }|]
    enumConstByName = sortOn constantName enumConstants
enumNameToValueInitList _ _ = error "enumNameToValueInitList: impossible happened."

allocatorTemplateName :: Bool -> Maybe String
allocatorTemplateName False = Nothing
allocatorTemplateName True = Just "_Alloc"

defaultAllocator  :: Bool -> Maybe String -> Maybe String
defaultAllocator True Nothing = Just []
defaultAllocator True allocator = allocator
defaultAllocator False _ = Nothing

needsTemplate :: [a] -> Bool -> Bool
needsTemplate declParams template_alloc_enabled = (not $ null declParams) || template_alloc_enabled

onlyTemplate :: [a] -> Bool -> Text -> Text
onlyTemplate declParams template_alloc_enabled x = if needsTemplate declParams template_alloc_enabled then x else mempty

onlyNonTemplate :: [a] -> Bool -> Text -> Text
onlyNonTemplate declParams template_alloc_enabled x = if not $ needsTemplate declParams template_alloc_enabled then x else mempty