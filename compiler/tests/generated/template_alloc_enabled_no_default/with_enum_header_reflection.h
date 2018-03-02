
#pragma once

#include "with_enum_header_types.h"
#include <bond/core/reflection.h>

namespace tests
{
    //
    // Foo
    //
    template <class _Alloc>
    struct Foo<_Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_m_bool_1_metadata;
        private: static const ::bond::Metadata s_m_bool_2_metadata;
        private: static const ::bond::Metadata s_m_bool_3_metadata;
        private: static const ::bond::Metadata s_m_str_1_metadata;
        private: static const ::bond::Metadata s_m_str_2_metadata;
        private: static const ::bond::Metadata s_m_int8_4_metadata;
        private: static const ::bond::Metadata s_m_int8_5_metadata;
        private: static const ::bond::Metadata s_m_int16_4_metadata;
        private: static const ::bond::Metadata s_m_int16_5_metadata;
        private: static const ::bond::Metadata s_m_int32_4_metadata;
        private: static const ::bond::Metadata s_m_int32_max_metadata;
        private: static const ::bond::Metadata s_m_int64_4_metadata;
        private: static const ::bond::Metadata s_m_int64_max_metadata;
        private: static const ::bond::Metadata s_m_uint8_2_metadata;
        private: static const ::bond::Metadata s_m_uint8_3_metadata;
        private: static const ::bond::Metadata s_m_uint16_2_metadata;
        private: static const ::bond::Metadata s_m_uint16_3_metadata;
        private: static const ::bond::Metadata s_m_uint32_3_metadata;
        private: static const ::bond::Metadata s_m_uint32_max_metadata;
        private: static const ::bond::Metadata s_m_uint64_3_metadata;
        private: static const ::bond::Metadata s_m_uint64_max_metadata;
        private: static const ::bond::Metadata s_m_double_3_metadata;
        private: static const ::bond::Metadata s_m_double_4_metadata;
        private: static const ::bond::Metadata s_m_double_5_metadata;
        private: static const ::bond::Metadata s_m_float_3_metadata;
        private: static const ::bond::Metadata s_m_float_4_metadata;
        private: static const ::bond::Metadata s_m_float_7_metadata;
        private: static const ::bond::Metadata s_m_enum1_metadata;
        private: static const ::bond::Metadata s_m_enum2_metadata;
        private: static const ::bond::Metadata s_m_enum3_metadata;
        private: static const ::bond::Metadata s_m_enum_int32min_metadata;
        private: static const ::bond::Metadata s_m_enum_int32max_metadata;
        private: static const ::bond::Metadata s_m_enum_uint32_min_metadata;
        private: static const ::bond::Metadata s_m_enum_uint32_max_metadata;
        private: static const ::bond::Metadata s_m_wstr_1_metadata;
        private: static const ::bond::Metadata s_m_wstr_2_metadata;

        public: struct var
        {
            // m_bool_1
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                bool,
                &Foo<_Alloc>::m_bool_1,
                &s_m_bool_1_metadata
            > {}  m_bool_1;
        
            // m_bool_2
            typedef struct : ::bond::reflection::FieldTemplate<
                1,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                bool,
                &Foo<_Alloc>::m_bool_2,
                &s_m_bool_2_metadata
            > {}  m_bool_2;
        
            // m_bool_3
            typedef struct : ::bond::reflection::FieldTemplate<
                2,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<bool>,
                &Foo<_Alloc>::m_bool_3,
                &s_m_bool_3_metadata
            > {}  m_bool_3;
        
            // m_str_1
            typedef struct : ::bond::reflection::FieldTemplate<
                3,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<_Alloc>::template rebind_alloc<char> >,
                &Foo<_Alloc>::m_str_1,
                &s_m_str_1_metadata
            > {}  m_str_1;
        
            // m_str_2
            typedef struct : ::bond::reflection::FieldTemplate<
                4,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<_Alloc>::template rebind_alloc<char> > >,
                &Foo<_Alloc>::m_str_2,
                &s_m_str_2_metadata
            > {}  m_str_2;
        
            // m_int8_4
            typedef struct : ::bond::reflection::FieldTemplate<
                5,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                int8_t,
                &Foo<_Alloc>::m_int8_4,
                &s_m_int8_4_metadata
            > {}  m_int8_4;
        
            // m_int8_5
            typedef struct : ::bond::reflection::FieldTemplate<
                6,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<int8_t>,
                &Foo<_Alloc>::m_int8_5,
                &s_m_int8_5_metadata
            > {}  m_int8_5;
        
            // m_int16_4
            typedef struct : ::bond::reflection::FieldTemplate<
                7,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                int16_t,
                &Foo<_Alloc>::m_int16_4,
                &s_m_int16_4_metadata
            > {}  m_int16_4;
        
            // m_int16_5
            typedef struct : ::bond::reflection::FieldTemplate<
                8,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<int16_t>,
                &Foo<_Alloc>::m_int16_5,
                &s_m_int16_5_metadata
            > {}  m_int16_5;
        
            // m_int32_4
            typedef struct : ::bond::reflection::FieldTemplate<
                9,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<int32_t>,
                &Foo<_Alloc>::m_int32_4,
                &s_m_int32_4_metadata
            > {}  m_int32_4;
        
            // m_int32_max
            typedef struct : ::bond::reflection::FieldTemplate<
                10,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                int32_t,
                &Foo<_Alloc>::m_int32_max,
                &s_m_int32_max_metadata
            > {}  m_int32_max;
        
            // m_int64_4
            typedef struct : ::bond::reflection::FieldTemplate<
                11,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<int64_t>,
                &Foo<_Alloc>::m_int64_4,
                &s_m_int64_4_metadata
            > {}  m_int64_4;
        
            // m_int64_max
            typedef struct : ::bond::reflection::FieldTemplate<
                12,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                int64_t,
                &Foo<_Alloc>::m_int64_max,
                &s_m_int64_max_metadata
            > {}  m_int64_max;
        
            // m_uint8_2
            typedef struct : ::bond::reflection::FieldTemplate<
                13,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                uint8_t,
                &Foo<_Alloc>::m_uint8_2,
                &s_m_uint8_2_metadata
            > {}  m_uint8_2;
        
            // m_uint8_3
            typedef struct : ::bond::reflection::FieldTemplate<
                14,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<uint8_t>,
                &Foo<_Alloc>::m_uint8_3,
                &s_m_uint8_3_metadata
            > {}  m_uint8_3;
        
            // m_uint16_2
            typedef struct : ::bond::reflection::FieldTemplate<
                15,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                uint16_t,
                &Foo<_Alloc>::m_uint16_2,
                &s_m_uint16_2_metadata
            > {}  m_uint16_2;
        
            // m_uint16_3
            typedef struct : ::bond::reflection::FieldTemplate<
                16,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<uint16_t>,
                &Foo<_Alloc>::m_uint16_3,
                &s_m_uint16_3_metadata
            > {}  m_uint16_3;
        
            // m_uint32_3
            typedef struct : ::bond::reflection::FieldTemplate<
                17,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<uint32_t>,
                &Foo<_Alloc>::m_uint32_3,
                &s_m_uint32_3_metadata
            > {}  m_uint32_3;
        
            // m_uint32_max
            typedef struct : ::bond::reflection::FieldTemplate<
                18,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                uint32_t,
                &Foo<_Alloc>::m_uint32_max,
                &s_m_uint32_max_metadata
            > {}  m_uint32_max;
        
            // m_uint64_3
            typedef struct : ::bond::reflection::FieldTemplate<
                19,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<uint64_t>,
                &Foo<_Alloc>::m_uint64_3,
                &s_m_uint64_3_metadata
            > {}  m_uint64_3;
        
            // m_uint64_max
            typedef struct : ::bond::reflection::FieldTemplate<
                20,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                uint64_t,
                &Foo<_Alloc>::m_uint64_max,
                &s_m_uint64_max_metadata
            > {}  m_uint64_max;
        
            // m_double_3
            typedef struct : ::bond::reflection::FieldTemplate<
                21,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<double>,
                &Foo<_Alloc>::m_double_3,
                &s_m_double_3_metadata
            > {}  m_double_3;
        
            // m_double_4
            typedef struct : ::bond::reflection::FieldTemplate<
                22,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                double,
                &Foo<_Alloc>::m_double_4,
                &s_m_double_4_metadata
            > {}  m_double_4;
        
            // m_double_5
            typedef struct : ::bond::reflection::FieldTemplate<
                23,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                double,
                &Foo<_Alloc>::m_double_5,
                &s_m_double_5_metadata
            > {}  m_double_5;
        
            // m_float_3
            typedef struct : ::bond::reflection::FieldTemplate<
                24,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<float>,
                &Foo<_Alloc>::m_float_3,
                &s_m_float_3_metadata
            > {}  m_float_3;
        
            // m_float_4
            typedef struct : ::bond::reflection::FieldTemplate<
                25,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                float,
                &Foo<_Alloc>::m_float_4,
                &s_m_float_4_metadata
            > {}  m_float_4;
        
            // m_float_7
            typedef struct : ::bond::reflection::FieldTemplate<
                26,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                float,
                &Foo<_Alloc>::m_float_7,
                &s_m_float_7_metadata
            > {}  m_float_7;
        
            // m_enum1
            typedef struct : ::bond::reflection::FieldTemplate<
                27,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::tests::EnumType1,
                &Foo<_Alloc>::m_enum1,
                &s_m_enum1_metadata
            > {}  m_enum1;
        
            // m_enum2
            typedef struct : ::bond::reflection::FieldTemplate<
                28,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::tests::EnumType1,
                &Foo<_Alloc>::m_enum2,
                &s_m_enum2_metadata
            > {}  m_enum2;
        
            // m_enum3
            typedef struct : ::bond::reflection::FieldTemplate<
                29,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe< ::tests::EnumType1>,
                &Foo<_Alloc>::m_enum3,
                &s_m_enum3_metadata
            > {}  m_enum3;
        
            // m_enum_int32min
            typedef struct : ::bond::reflection::FieldTemplate<
                30,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::tests::EnumType1,
                &Foo<_Alloc>::m_enum_int32min,
                &s_m_enum_int32min_metadata
            > {}  m_enum_int32min;
        
            // m_enum_int32max
            typedef struct : ::bond::reflection::FieldTemplate<
                31,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::tests::EnumType1,
                &Foo<_Alloc>::m_enum_int32max,
                &s_m_enum_int32max_metadata
            > {}  m_enum_int32max;
        
            // m_enum_uint32_min
            typedef struct : ::bond::reflection::FieldTemplate<
                32,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::tests::EnumType1,
                &Foo<_Alloc>::m_enum_uint32_min,
                &s_m_enum_uint32_min_metadata
            > {}  m_enum_uint32_min;
        
            // m_enum_uint32_max
            typedef struct : ::bond::reflection::FieldTemplate<
                33,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::tests::EnumType1,
                &Foo<_Alloc>::m_enum_uint32_max,
                &s_m_enum_uint32_max_metadata
            > {}  m_enum_uint32_max;
        
            // m_wstr_1
            typedef struct : ::bond::reflection::FieldTemplate<
                34,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                std::basic_string<wchar_t, std::char_traits<wchar_t>, typename std::allocator_traits<_Alloc>::template rebind_alloc<wchar_t> >,
                &Foo<_Alloc>::m_wstr_1,
                &s_m_wstr_1_metadata
            > {}  m_wstr_1;
        
            // m_wstr_2
            typedef struct : ::bond::reflection::FieldTemplate<
                35,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                ::bond::maybe<std::basic_string<wchar_t, std::char_traits<wchar_t>, typename std::allocator_traits<_Alloc>::template rebind_alloc<wchar_t> > >,
                &Foo<_Alloc>::m_wstr_2,
                &s_m_wstr_2_metadata
            > {}  m_wstr_2;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::m_wstr_2>::type fields1;
        private: typedef typename boost::mpl::push_front<fields1, typename var::m_wstr_1>::type fields2;
        private: typedef typename boost::mpl::push_front<fields2, typename var::m_enum_uint32_max>::type fields3;
        private: typedef typename boost::mpl::push_front<fields3, typename var::m_enum_uint32_min>::type fields4;
        private: typedef typename boost::mpl::push_front<fields4, typename var::m_enum_int32max>::type fields5;
        private: typedef typename boost::mpl::push_front<fields5, typename var::m_enum_int32min>::type fields6;
        private: typedef typename boost::mpl::push_front<fields6, typename var::m_enum3>::type fields7;
        private: typedef typename boost::mpl::push_front<fields7, typename var::m_enum2>::type fields8;
        private: typedef typename boost::mpl::push_front<fields8, typename var::m_enum1>::type fields9;
        private: typedef typename boost::mpl::push_front<fields9, typename var::m_float_7>::type fields10;
        private: typedef typename boost::mpl::push_front<fields10, typename var::m_float_4>::type fields11;
        private: typedef typename boost::mpl::push_front<fields11, typename var::m_float_3>::type fields12;
        private: typedef typename boost::mpl::push_front<fields12, typename var::m_double_5>::type fields13;
        private: typedef typename boost::mpl::push_front<fields13, typename var::m_double_4>::type fields14;
        private: typedef typename boost::mpl::push_front<fields14, typename var::m_double_3>::type fields15;
        private: typedef typename boost::mpl::push_front<fields15, typename var::m_uint64_max>::type fields16;
        private: typedef typename boost::mpl::push_front<fields16, typename var::m_uint64_3>::type fields17;
        private: typedef typename boost::mpl::push_front<fields17, typename var::m_uint32_max>::type fields18;
        private: typedef typename boost::mpl::push_front<fields18, typename var::m_uint32_3>::type fields19;
        private: typedef typename boost::mpl::push_front<fields19, typename var::m_uint16_3>::type fields20;
        private: typedef typename boost::mpl::push_front<fields20, typename var::m_uint16_2>::type fields21;
        private: typedef typename boost::mpl::push_front<fields21, typename var::m_uint8_3>::type fields22;
        private: typedef typename boost::mpl::push_front<fields22, typename var::m_uint8_2>::type fields23;
        private: typedef typename boost::mpl::push_front<fields23, typename var::m_int64_max>::type fields24;
        private: typedef typename boost::mpl::push_front<fields24, typename var::m_int64_4>::type fields25;
        private: typedef typename boost::mpl::push_front<fields25, typename var::m_int32_max>::type fields26;
        private: typedef typename boost::mpl::push_front<fields26, typename var::m_int32_4>::type fields27;
        private: typedef typename boost::mpl::push_front<fields27, typename var::m_int16_5>::type fields28;
        private: typedef typename boost::mpl::push_front<fields28, typename var::m_int16_4>::type fields29;
        private: typedef typename boost::mpl::push_front<fields29, typename var::m_int8_5>::type fields30;
        private: typedef typename boost::mpl::push_front<fields30, typename var::m_int8_4>::type fields31;
        private: typedef typename boost::mpl::push_front<fields31, typename var::m_str_2>::type fields32;
        private: typedef typename boost::mpl::push_front<fields32, typename var::m_str_1>::type fields33;
        private: typedef typename boost::mpl::push_front<fields33, typename var::m_bool_3>::type fields34;
        private: typedef typename boost::mpl::push_front<fields34, typename var::m_bool_2>::type fields35;
        private: typedef typename boost::mpl::push_front<fields35, typename var::m_bool_1>::type fields36;

        public: typedef typename fields36::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_m_bool_1_metadata;
            (void)s_m_bool_2_metadata;
            (void)s_m_bool_3_metadata;
            (void)s_m_str_1_metadata;
            (void)s_m_str_2_metadata;
            (void)s_m_int8_4_metadata;
            (void)s_m_int8_5_metadata;
            (void)s_m_int16_4_metadata;
            (void)s_m_int16_5_metadata;
            (void)s_m_int32_4_metadata;
            (void)s_m_int32_max_metadata;
            (void)s_m_int64_4_metadata;
            (void)s_m_int64_max_metadata;
            (void)s_m_uint8_2_metadata;
            (void)s_m_uint8_3_metadata;
            (void)s_m_uint16_2_metadata;
            (void)s_m_uint16_3_metadata;
            (void)s_m_uint32_3_metadata;
            (void)s_m_uint32_max_metadata;
            (void)s_m_uint64_3_metadata;
            (void)s_m_uint64_max_metadata;
            (void)s_m_double_3_metadata;
            (void)s_m_double_4_metadata;
            (void)s_m_double_5_metadata;
            (void)s_m_float_3_metadata;
            (void)s_m_float_4_metadata;
            (void)s_m_float_7_metadata;
            (void)s_m_enum1_metadata;
            (void)s_m_enum2_metadata;
            (void)s_m_enum3_metadata;
            (void)s_m_enum_int32min_metadata;
            (void)s_m_enum_int32max_metadata;
            (void)s_m_enum_uint32_min_metadata;
            (void)s_m_enum_uint32_max_metadata;
            (void)s_m_wstr_1_metadata;
            (void)s_m_wstr_2_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("Foo", "tests.Foo",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::metadata
        = Foo<_Alloc>::Schema::GetMetadata();
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_bool_1_metadata
        = ::bond::reflection::MetadataInit(true, "m_bool_1");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_bool_2_metadata
        = ::bond::reflection::MetadataInit(false, "m_bool_2");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_bool_3_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_bool_3");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_str_1_metadata
        = ::bond::reflection::MetadataInit("default string value", "m_str_1");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_str_2_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_str_2");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_int8_4_metadata
        = ::bond::reflection::MetadataInit(static_cast<int8_t>(-127), "m_int8_4");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_int8_5_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_int8_5");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_int16_4_metadata
        = ::bond::reflection::MetadataInit(static_cast<int16_t>(-32767), "m_int16_4");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_int16_5_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_int16_5");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_int32_4_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_int32_4");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_int32_max_metadata
        = ::bond::reflection::MetadataInit(static_cast<int32_t>(2147483647), "m_int32_max");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_int64_4_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_int64_4");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_int64_max_metadata
        = ::bond::reflection::MetadataInit(static_cast<int64_t>(9223372036854775807LL), "m_int64_max");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_uint8_2_metadata
        = ::bond::reflection::MetadataInit(static_cast<uint8_t>(255), "m_uint8_2");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_uint8_3_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_uint8_3");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_uint16_2_metadata
        = ::bond::reflection::MetadataInit(static_cast<uint16_t>(65535), "m_uint16_2");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_uint16_3_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_uint16_3");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_uint32_3_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_uint32_3");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_uint32_max_metadata
        = ::bond::reflection::MetadataInit(static_cast<uint32_t>(4294967295), "m_uint32_max");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_uint64_3_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_uint64_3");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_uint64_max_metadata
        = ::bond::reflection::MetadataInit(static_cast<uint64_t>(18446744073709551615ULL), "m_uint64_max");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_double_3_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_double_3");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_double_4_metadata
        = ::bond::reflection::MetadataInit(static_cast<double>(-123.456789), "m_double_4");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_double_5_metadata
        = ::bond::reflection::MetadataInit(static_cast<double>(-0.0), "m_double_5");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_float_3_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_float_3");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_float_4_metadata
        = ::bond::reflection::MetadataInit(static_cast<float>(2.71828183f), "m_float_4");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_float_7_metadata
        = ::bond::reflection::MetadataInit(static_cast<float>(0.0f), "m_float_7");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_enum1_metadata
        = ::bond::reflection::MetadataInit(::tests::_bond_enumerators::EnumType1::EnumValue1, "m_enum1");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_enum2_metadata
        = ::bond::reflection::MetadataInit(::tests::_bond_enumerators::EnumType1::EnumValue3, "m_enum2");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_enum3_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_enum3");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_enum_int32min_metadata
        = ::bond::reflection::MetadataInit(::tests::_bond_enumerators::EnumType1::Int32Min, "m_enum_int32min");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_enum_int32max_metadata
        = ::bond::reflection::MetadataInit(::tests::_bond_enumerators::EnumType1::Int32Max, "m_enum_int32max");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_enum_uint32_min_metadata
        = ::bond::reflection::MetadataInit(::tests::_bond_enumerators::EnumType1::UInt32Min, "m_enum_uint32_min");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_enum_uint32_max_metadata
        = ::bond::reflection::MetadataInit(::tests::_bond_enumerators::EnumType1::UInt32Max, "m_enum_uint32_max");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_wstr_1_metadata
        = ::bond::reflection::MetadataInit(L"default wstring value", "m_wstr_1");
    
    template <class _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::s_m_wstr_2_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m_wstr_2");

    
} // namespace tests
