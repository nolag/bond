
#pragma once

#include "basic_types_nsmapped_types.h"
#include <bond/core/reflection.h>

namespace nsmapped
{
    //
    // BasicTypes
    //
    template <typename _Alloc>
    struct BasicTypes<_Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s__bool_metadata;
        private: static const ::bond::Metadata s__str_metadata;
        private: static const ::bond::Metadata s__wstr_metadata;
        private: static const ::bond::Metadata s__uint64_metadata;
        private: static const ::bond::Metadata s__uint16_metadata;
        private: static const ::bond::Metadata s__uint32_metadata;
        private: static const ::bond::Metadata s__uint8_metadata;
        private: static const ::bond::Metadata s__int8_metadata;
        private: static const ::bond::Metadata s__int16_metadata;
        private: static const ::bond::Metadata s__int32_metadata;
        private: static const ::bond::Metadata s__int64_metadata;
        private: static const ::bond::Metadata s__double_metadata;
        private: static const ::bond::Metadata s__float_metadata;
        private: static const ::bond::Metadata s__blob_metadata;

        public: struct var
        {
            // _bool
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                bool,
                &BasicTypes<_Alloc>::_bool,
                &s__bool_metadata
            > {}  _bool;
        
            // _str
            typedef struct : ::bond::reflection::FieldTemplate<
                2,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<_Alloc>::template rebind_alloc<char> >,
                &BasicTypes<_Alloc>::_str,
                &s__str_metadata
            > {}  _str;
        
            // _wstr
            typedef struct : ::bond::reflection::FieldTemplate<
                3,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                std::basic_string<wchar_t, std::char_traits<wchar_t>, typename std::allocator_traits<_Alloc>::template rebind_alloc<wchar_t> >,
                &BasicTypes<_Alloc>::_wstr,
                &s__wstr_metadata
            > {}  _wstr;
        
            // _uint64
            typedef struct : ::bond::reflection::FieldTemplate<
                10,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                uint64_t,
                &BasicTypes<_Alloc>::_uint64,
                &s__uint64_metadata
            > {}  _uint64;
        
            // _uint16
            typedef struct : ::bond::reflection::FieldTemplate<
                11,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                uint16_t,
                &BasicTypes<_Alloc>::_uint16,
                &s__uint16_metadata
            > {}  _uint16;
        
            // _uint32
            typedef struct : ::bond::reflection::FieldTemplate<
                12,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                uint32_t,
                &BasicTypes<_Alloc>::_uint32,
                &s__uint32_metadata
            > {}  _uint32;
        
            // _uint8
            typedef struct : ::bond::reflection::FieldTemplate<
                13,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                uint8_t,
                &BasicTypes<_Alloc>::_uint8,
                &s__uint8_metadata
            > {}  _uint8;
        
            // _int8
            typedef struct : ::bond::reflection::FieldTemplate<
                14,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                int8_t,
                &BasicTypes<_Alloc>::_int8,
                &s__int8_metadata
            > {}  _int8;
        
            // _int16
            typedef struct : ::bond::reflection::FieldTemplate<
                15,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                int16_t,
                &BasicTypes<_Alloc>::_int16,
                &s__int16_metadata
            > {}  _int16;
        
            // _int32
            typedef struct : ::bond::reflection::FieldTemplate<
                16,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                int32_t,
                &BasicTypes<_Alloc>::_int32,
                &s__int32_metadata
            > {}  _int32;
        
            // _int64
            typedef struct : ::bond::reflection::FieldTemplate<
                17,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                int64_t,
                &BasicTypes<_Alloc>::_int64,
                &s__int64_metadata
            > {}  _int64;
        
            // _double
            typedef struct : ::bond::reflection::FieldTemplate<
                18,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                double,
                &BasicTypes<_Alloc>::_double,
                &s__double_metadata
            > {}  _double;
        
            // _float
            typedef struct : ::bond::reflection::FieldTemplate<
                20,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                float,
                &BasicTypes<_Alloc>::_float,
                &s__float_metadata
            > {}  _float;
        
            // _blob
            typedef struct : ::bond::reflection::FieldTemplate<
                21,
                ::bond::reflection::optional_field_modifier,
                BasicTypes<_Alloc>,
                ::bond::blob,
                &BasicTypes<_Alloc>::_blob,
                &s__blob_metadata
            > {}  _blob;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::_blob>::type fields1;
        private: typedef typename boost::mpl::push_front<fields1, typename var::_float>::type fields2;
        private: typedef typename boost::mpl::push_front<fields2, typename var::_double>::type fields3;
        private: typedef typename boost::mpl::push_front<fields3, typename var::_int64>::type fields4;
        private: typedef typename boost::mpl::push_front<fields4, typename var::_int32>::type fields5;
        private: typedef typename boost::mpl::push_front<fields5, typename var::_int16>::type fields6;
        private: typedef typename boost::mpl::push_front<fields6, typename var::_int8>::type fields7;
        private: typedef typename boost::mpl::push_front<fields7, typename var::_uint8>::type fields8;
        private: typedef typename boost::mpl::push_front<fields8, typename var::_uint32>::type fields9;
        private: typedef typename boost::mpl::push_front<fields9, typename var::_uint16>::type fields10;
        private: typedef typename boost::mpl::push_front<fields10, typename var::_uint64>::type fields11;
        private: typedef typename boost::mpl::push_front<fields11, typename var::_wstr>::type fields12;
        private: typedef typename boost::mpl::push_front<fields12, typename var::_str>::type fields13;
        private: typedef typename boost::mpl::push_front<fields13, typename var::_bool>::type fields14;

        public: typedef typename fields14::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s__bool_metadata;
            (void)s__str_metadata;
            (void)s__wstr_metadata;
            (void)s__uint64_metadata;
            (void)s__uint16_metadata;
            (void)s__uint32_metadata;
            (void)s__uint8_metadata;
            (void)s__int8_metadata;
            (void)s__int16_metadata;
            (void)s__int32_metadata;
            (void)s__int64_metadata;
            (void)s__double_metadata;
            (void)s__float_metadata;
            (void)s__blob_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("BasicTypes", "tests.BasicTypes",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::metadata
        = BasicTypes<_Alloc>::Schema::GetMetadata();
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__bool_metadata
        = ::bond::reflection::MetadataInit("_bool");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__str_metadata
        = ::bond::reflection::MetadataInit("_str");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__wstr_metadata
        = ::bond::reflection::MetadataInit("_wstr");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__uint64_metadata
        = ::bond::reflection::MetadataInit("_uint64");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__uint16_metadata
        = ::bond::reflection::MetadataInit("_uint16");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__uint32_metadata
        = ::bond::reflection::MetadataInit("_uint32");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__uint8_metadata
        = ::bond::reflection::MetadataInit("_uint8");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__int8_metadata
        = ::bond::reflection::MetadataInit("_int8");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__int16_metadata
        = ::bond::reflection::MetadataInit("_int16");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__int32_metadata
        = ::bond::reflection::MetadataInit("_int32");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__int64_metadata
        = ::bond::reflection::MetadataInit("_int64");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__double_metadata
        = ::bond::reflection::MetadataInit("_double");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__float_metadata
        = ::bond::reflection::MetadataInit("_float");
    
    template <typename _Alloc>
    const ::bond::Metadata BasicTypes<_Alloc>::Schema::s__blob_metadata
        = ::bond::reflection::MetadataInit("_blob");

    
} // namespace nsmapped
