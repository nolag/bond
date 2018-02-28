
#pragma once

#include <bond/core/bond_version.h>

#if BOND_VERSION < 0x0700
#error This file was generated by a newer version of the Bond compiler and is incompatible with your version of the Bond library.
#endif

#if BOND_MIN_CODEGEN_VERSION > 0x0b00
#error This file was generated by an older version of the Bond compiler and is incompatible with your version of the Bond library.
#endif

#include <bond/core/config.h>
#include <bond/core/containers.h>
#include <scoped_allocator>


namespace tests
{
    
    namespace _bond_enumerators
    {
    namespace EnumType1
    {
        enum EnumType1
        {
            EnumValue1 = static_cast<int32_t>(5),
            EnumValue2 = static_cast<int32_t>(10),
            EnumValue3 = static_cast<int32_t>(-10),
            EnumValue4 = static_cast<int32_t>(42),
            Low = static_cast<int32_t>(1),
            EnumValue5 = static_cast<int32_t>(-10),
            EnumValue6 = static_cast<int32_t>(4294967286),
            Int32Min = static_cast<int32_t>(-2147483647-1),
            Int32Max = static_cast<int32_t>(2147483647),
            UInt32Min = static_cast<int32_t>(0),
            UInt32Max = static_cast<int32_t>(4294967295),
            HexNeg = static_cast<int32_t>(-255),
            OctNeg = static_cast<int32_t>(-83)
        };
        
        inline BOND_CONSTEXPR const char* GetTypeName(enum EnumType1)
        {
            return "EnumType1";
        }

        inline BOND_CONSTEXPR const char* GetTypeName(enum EnumType1, const ::bond::qualified_name_tag&)
        {
            return "tests.EnumType1";
        }

#if defined(_MSC_VER) && (_MSC_VER < 1900) // Versions of MSVC prior to 1900 do not support magic statics
        extern const std::map<enum EnumType1, std::string> _value_to_name_EnumType1;

        inline const std::map<enum EnumType1, std::string>& GetValueToNameMap(enum EnumType1)
        {
            return _value_to_name_EnumType1;
        }

        extern const std::map<std::string, enum EnumType1> _name_to_value_EnumType1;

        inline const std::map<std::string, enum EnumType1>& GetNameToValueMap(enum EnumType1)
        {
            return _name_to_value_EnumType1;
        }
#else
        template <typename Map = std::map<enum EnumType1, std::string> >
        inline const Map& GetValueToNameMap(enum EnumType1, ::bond::detail::mpl::identity<Map> = {})
        {
            static const Map s_valueToNameMap
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
            return s_valueToNameMap;
        }

        template <typename Map = std::map<std::string, enum EnumType1> >
        inline const Map& GetNameToValueMap(enum EnumType1, ::bond::detail::mpl::identity<Map> = {})
        {
            static const Map s_nameToValueMap
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
            return s_nameToValueMap;
        }
#endif
        const std::string& ToString(enum EnumType1 value);

        void FromString(const std::string& name, enum EnumType1& value);

        bool ToEnum(enum EnumType1& value, const std::string& name);

        bool FromEnum(std::string& name, enum EnumType1 value);

    } // namespace EnumType1
    } // namespace _bond_enumerators

    using namespace _bond_enumerators::EnumType1;
    

    
    struct Foo
    {
        bool m_bool_1;
        bool m_bool_2;
        ::bond::maybe<bool> m_bool_3;
        std::basic_string<char, std::char_traits<char>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<char> > > m_str_1;
        ::bond::maybe<std::basic_string<char, std::char_traits<char>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<char> > > > m_str_2;
        int8_t m_int8_4;
        ::bond::maybe<int8_t> m_int8_5;
        int16_t m_int16_4;
        ::bond::maybe<int16_t> m_int16_5;
        ::bond::maybe<int32_t> m_int32_4;
        int32_t m_int32_max;
        ::bond::maybe<int64_t> m_int64_4;
        int64_t m_int64_max;
        uint8_t m_uint8_2;
        ::bond::maybe<uint8_t> m_uint8_3;
        uint16_t m_uint16_2;
        ::bond::maybe<uint16_t> m_uint16_3;
        ::bond::maybe<uint32_t> m_uint32_3;
        uint32_t m_uint32_max;
        ::bond::maybe<uint64_t> m_uint64_3;
        uint64_t m_uint64_max;
        ::bond::maybe<double> m_double_3;
        double m_double_4;
        double m_double_5;
        ::bond::maybe<float> m_float_3;
        float m_float_4;
        float m_float_7;
        ::tests::EnumType1 m_enum1;
        ::tests::EnumType1 m_enum2;
        ::bond::maybe< ::tests::EnumType1> m_enum3;
        ::tests::EnumType1 m_enum_int32min;
        ::tests::EnumType1 m_enum_int32max;
        ::tests::EnumType1 m_enum_uint32_min;
        ::tests::EnumType1 m_enum_uint32_max;
        std::basic_string<wchar_t, std::char_traits<wchar_t>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<wchar_t> > > m_wstr_1;
        ::bond::maybe<std::basic_string<wchar_t, std::char_traits<wchar_t>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<wchar_t> > > > m_wstr_2;
        int64_t m_int64_neg_hex;
        int64_t m_int64_neg_oct;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        Foo(_bond_vc12_ctor_workaround_ = {})
          : m_bool_1(true),
            m_bool_2(false),
            m_str_1("default string value"),
            m_int8_4(-127),
            m_int16_4(-32767),
            m_int32_max(2147483647),
            m_int64_max(9223372036854775807LL),
            m_uint8_2(255),
            m_uint16_2(65535),
            m_uint32_max(4294967295),
            m_uint64_max(18446744073709551615ULL),
            m_double_4(-123.456789),
            m_double_5(-0.0),
            m_float_4(2.71828183f),
            m_float_7(0.0f),
            m_enum1(::tests::_bond_enumerators::EnumType1::EnumValue1),
            m_enum2(::tests::_bond_enumerators::EnumType1::EnumValue3),
            m_enum_int32min(::tests::_bond_enumerators::EnumType1::Int32Min),
            m_enum_int32max(::tests::_bond_enumerators::EnumType1::Int32Max),
            m_enum_uint32_min(::tests::_bond_enumerators::EnumType1::UInt32Min),
            m_enum_uint32_max(::tests::_bond_enumerators::EnumType1::UInt32Max),
            m_wstr_1(L"default wstring value"),
            m_int64_neg_hex(-4095LL),
            m_int64_neg_oct(-83LL)
        {
        }
        
        // Compiler generated copy ctor OK
        Foo(const Foo&) = default;
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Foo(Foo&& other)
          : m_bool_1(std::move(other.m_bool_1)),
            m_bool_2(std::move(other.m_bool_2)),
            m_bool_3(std::move(other.m_bool_3)),
            m_str_1(std::move(other.m_str_1)),
            m_str_2(std::move(other.m_str_2)),
            m_int8_4(std::move(other.m_int8_4)),
            m_int8_5(std::move(other.m_int8_5)),
            m_int16_4(std::move(other.m_int16_4)),
            m_int16_5(std::move(other.m_int16_5)),
            m_int32_4(std::move(other.m_int32_4)),
            m_int32_max(std::move(other.m_int32_max)),
            m_int64_4(std::move(other.m_int64_4)),
            m_int64_max(std::move(other.m_int64_max)),
            m_uint8_2(std::move(other.m_uint8_2)),
            m_uint8_3(std::move(other.m_uint8_3)),
            m_uint16_2(std::move(other.m_uint16_2)),
            m_uint16_3(std::move(other.m_uint16_3)),
            m_uint32_3(std::move(other.m_uint32_3)),
            m_uint32_max(std::move(other.m_uint32_max)),
            m_uint64_3(std::move(other.m_uint64_3)),
            m_uint64_max(std::move(other.m_uint64_max)),
            m_double_3(std::move(other.m_double_3)),
            m_double_4(std::move(other.m_double_4)),
            m_double_5(std::move(other.m_double_5)),
            m_float_3(std::move(other.m_float_3)),
            m_float_4(std::move(other.m_float_4)),
            m_float_7(std::move(other.m_float_7)),
            m_enum1(std::move(other.m_enum1)),
            m_enum2(std::move(other.m_enum2)),
            m_enum3(std::move(other.m_enum3)),
            m_enum_int32min(std::move(other.m_enum_int32min)),
            m_enum_int32max(std::move(other.m_enum_int32max)),
            m_enum_uint32_min(std::move(other.m_enum_uint32_min)),
            m_enum_uint32_max(std::move(other.m_enum_uint32_max)),
            m_wstr_1(std::move(other.m_wstr_1)),
            m_wstr_2(std::move(other.m_wstr_2)),
            m_int64_neg_hex(std::move(other.m_int64_neg_hex)),
            m_int64_neg_oct(std::move(other.m_int64_neg_oct))
        {
        }
#else
        Foo(Foo&&) = default;
#endif
        
        explicit
        Foo(const arena& allocator)
          : m_bool_1(true),
            m_bool_2(false),
            m_bool_3(),
            m_str_1("default string value", allocator),
            m_str_2(allocator),
            m_int8_4(-127),
            m_int8_5(),
            m_int16_4(-32767),
            m_int16_5(),
            m_int32_4(),
            m_int32_max(2147483647),
            m_int64_4(),
            m_int64_max(9223372036854775807LL),
            m_uint8_2(255),
            m_uint8_3(),
            m_uint16_2(65535),
            m_uint16_3(),
            m_uint32_3(),
            m_uint32_max(4294967295),
            m_uint64_3(),
            m_uint64_max(18446744073709551615ULL),
            m_double_3(),
            m_double_4(-123.456789),
            m_double_5(-0.0),
            m_float_3(),
            m_float_4(2.71828183f),
            m_float_7(0.0f),
            m_enum1(::tests::_bond_enumerators::EnumType1::EnumValue1),
            m_enum2(::tests::_bond_enumerators::EnumType1::EnumValue3),
            m_enum3(),
            m_enum_int32min(::tests::_bond_enumerators::EnumType1::Int32Min),
            m_enum_int32max(::tests::_bond_enumerators::EnumType1::Int32Max),
            m_enum_uint32_min(::tests::_bond_enumerators::EnumType1::UInt32Min),
            m_enum_uint32_max(::tests::_bond_enumerators::EnumType1::UInt32Max),
            m_wstr_1(L"default wstring value", allocator),
            m_wstr_2(allocator),
            m_int64_neg_hex(-4095LL),
            m_int64_neg_oct(-83LL)
        {
        }
        
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Foo& operator=(Foo other)
        {
            other.swap(*this);
            return *this;
        }
#else
        // Compiler generated operator= OK
        Foo& operator=(const Foo&) = default;
        Foo& operator=(Foo&&) = default;
#endif

        bool operator==(const Foo& other) const
        {
            return true
                && (m_bool_1 == other.m_bool_1)
                && (m_bool_2 == other.m_bool_2)
                && (m_bool_3 == other.m_bool_3)
                && (m_str_1 == other.m_str_1)
                && (m_str_2 == other.m_str_2)
                && (m_int8_4 == other.m_int8_4)
                && (m_int8_5 == other.m_int8_5)
                && (m_int16_4 == other.m_int16_4)
                && (m_int16_5 == other.m_int16_5)
                && (m_int32_4 == other.m_int32_4)
                && (m_int32_max == other.m_int32_max)
                && (m_int64_4 == other.m_int64_4)
                && (m_int64_max == other.m_int64_max)
                && (m_uint8_2 == other.m_uint8_2)
                && (m_uint8_3 == other.m_uint8_3)
                && (m_uint16_2 == other.m_uint16_2)
                && (m_uint16_3 == other.m_uint16_3)
                && (m_uint32_3 == other.m_uint32_3)
                && (m_uint32_max == other.m_uint32_max)
                && (m_uint64_3 == other.m_uint64_3)
                && (m_uint64_max == other.m_uint64_max)
                && (m_double_3 == other.m_double_3)
                && (m_double_4 == other.m_double_4)
                && (m_double_5 == other.m_double_5)
                && (m_float_3 == other.m_float_3)
                && (m_float_4 == other.m_float_4)
                && (m_float_7 == other.m_float_7)
                && (m_enum1 == other.m_enum1)
                && (m_enum2 == other.m_enum2)
                && (m_enum3 == other.m_enum3)
                && (m_enum_int32min == other.m_enum_int32min)
                && (m_enum_int32max == other.m_enum_int32max)
                && (m_enum_uint32_min == other.m_enum_uint32_min)
                && (m_enum_uint32_max == other.m_enum_uint32_max)
                && (m_wstr_1 == other.m_wstr_1)
                && (m_wstr_2 == other.m_wstr_2)
                && (m_int64_neg_hex == other.m_int64_neg_hex)
                && (m_int64_neg_oct == other.m_int64_neg_oct);
        }

        bool operator!=(const Foo& other) const
        {
            return !(*this == other);
        }

        void swap(Foo& other)
        {
            using std::swap;
            swap(m_bool_1, other.m_bool_1);
            swap(m_bool_2, other.m_bool_2);
            swap(m_bool_3, other.m_bool_3);
            swap(m_str_1, other.m_str_1);
            swap(m_str_2, other.m_str_2);
            swap(m_int8_4, other.m_int8_4);
            swap(m_int8_5, other.m_int8_5);
            swap(m_int16_4, other.m_int16_4);
            swap(m_int16_5, other.m_int16_5);
            swap(m_int32_4, other.m_int32_4);
            swap(m_int32_max, other.m_int32_max);
            swap(m_int64_4, other.m_int64_4);
            swap(m_int64_max, other.m_int64_max);
            swap(m_uint8_2, other.m_uint8_2);
            swap(m_uint8_3, other.m_uint8_3);
            swap(m_uint16_2, other.m_uint16_2);
            swap(m_uint16_3, other.m_uint16_3);
            swap(m_uint32_3, other.m_uint32_3);
            swap(m_uint32_max, other.m_uint32_max);
            swap(m_uint64_3, other.m_uint64_3);
            swap(m_uint64_max, other.m_uint64_max);
            swap(m_double_3, other.m_double_3);
            swap(m_double_4, other.m_double_4);
            swap(m_double_5, other.m_double_5);
            swap(m_float_3, other.m_float_3);
            swap(m_float_4, other.m_float_4);
            swap(m_float_7, other.m_float_7);
            swap(m_enum1, other.m_enum1);
            swap(m_enum2, other.m_enum2);
            swap(m_enum3, other.m_enum3);
            swap(m_enum_int32min, other.m_enum_int32min);
            swap(m_enum_int32max, other.m_enum_int32max);
            swap(m_enum_uint32_min, other.m_enum_uint32_min);
            swap(m_enum_uint32_max, other.m_enum_uint32_max);
            swap(m_wstr_1, other.m_wstr_1);
            swap(m_wstr_2, other.m_wstr_2);
            swap(m_int64_neg_hex, other.m_int64_neg_hex);
            swap(m_int64_neg_oct, other.m_int64_neg_oct);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
        }
    };

    inline void swap(::tests::Foo& left, ::tests::Foo& right)
    {
        left.swap(right);
    }
} // namespace tests

namespace std
{
    template <typename _Alloc>
        struct uses_allocator< ::tests::Foo, _Alloc>
        : is_convertible<_Alloc, arena>
    {};
}


