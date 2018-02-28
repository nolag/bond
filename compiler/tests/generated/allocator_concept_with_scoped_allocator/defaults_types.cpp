
#include "defaults_reflection.h"
#include <bond/core/exception.h>
#include <unordered_map>

namespace tests
{
    
    namespace _bond_enumerators
    {
    namespace EnumType1
    {
#if defined(_MSC_VER) && (_MSC_VER < 1900)
        const std::map<std::string, enum EnumType1> _name_to_value_EnumType1
            {
                { "EnumValue1", EnumValue1 },
                { "EnumValue2", EnumValue2 },
                { "EnumValue3", EnumValue3 },
                { "EnumValue4", EnumValue4 },
                { "EnumValue5", EnumValue5 },
                { "EnumValue6", EnumValue6 },
                { "HexNeg", HexNeg },
                { "Int32Max", Int32Max },
                { "Int32Min", Int32Min },
                { "Low", Low },
                { "OctNeg", OctNeg },
                { "UInt32Max", UInt32Max },
                { "UInt32Min", UInt32Min }
            };

        const std::map<enum EnumType1, std::string> _value_to_name_EnumType1
            {
                { Int32Min, "Int32Min" },
                { HexNeg, "HexNeg" },
                { OctNeg, "OctNeg" },
                { EnumValue3, "EnumValue3" },
                { EnumValue5, "EnumValue5" },
                { UInt32Min, "UInt32Min" },
                { Low, "Low" },
                { EnumValue1, "EnumValue1" },
                { EnumValue2, "EnumValue2" },
                { EnumValue4, "EnumValue4" },
                { Int32Max, "Int32Max" },
                { EnumValue6, "EnumValue6" },
                { UInt32Max, "UInt32Max" }
            };
#else
        namespace
        {
            struct _hash_EnumType1
            {
                std::size_t operator()(enum EnumType1 value) const
                {
                    return static_cast<std::size_t>(value);
                }
            };
        }
#endif
        const std::string& ToString(enum EnumType1 value)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1900)
            const auto& map = GetValueToNameMap(value);
#else
            const auto& map = GetValueToNameMap<std::unordered_map<enum EnumType1, std::string, _hash_EnumType1> >(value);
#endif
            auto it = map.find(value);

            if (map.end() == it)
                ::bond::InvalidEnumValueException(value, "EnumType1");

            return it->second;
        }

        void FromString(const std::string& name, enum EnumType1& value)
        {
            if (!ToEnum(value, name))
                ::bond::InvalidEnumValueException(name.c_str(), "EnumType1");
        }

        bool ToEnum(enum EnumType1& value, const std::string& name)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1900)
            const auto& map = GetNameToValueMap(value);
#else
            const auto& map = GetNameToValueMap<std::unordered_map<std::string, enum EnumType1> >(value);
#endif
            auto it = map.find(name);

            if (map.end() == it)
                return false;

            value = it->second;

            return true;
        }

        bool FromEnum(std::string& name, enum EnumType1 value)
        {
#if defined(_MSC_VER) && (_MSC_VER < 1900)
            const auto& map = GetValueToNameMap(value);
#else
            const auto& map = GetValueToNameMap<std::unordered_map<enum EnumType1, std::string, _hash_EnumType1> >(value);
#endif
            auto it = map.find(value);

            if (map.end() == it)
                return false;

            name = it->second;

            return true;
        }

    } // namespace EnumType1
    } // namespace _bond_enumerators

    
} // namespace tests
