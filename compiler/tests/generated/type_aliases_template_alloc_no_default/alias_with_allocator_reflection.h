
#pragma once

#include "alias_with_allocator_types.h"
#include <bond/core/reflection.h>

namespace test
{
    //
    // foo
    //
    template <typename _Alloc>
    struct foo<_Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_l_metadata;
        private: static const ::bond::Metadata s_v_metadata;
        private: static const ::bond::Metadata s_s_metadata;
        private: static const ::bond::Metadata s_m_metadata;
        private: static const ::bond::Metadata s_st_metadata;
        private: static const ::bond::Metadata s_d_metadata;
        private: static const ::bond::Metadata s_l1_metadata;
        private: static const ::bond::Metadata s_v1_metadata;
        private: static const ::bond::Metadata s_s1_metadata;
        private: static const ::bond::Metadata s_m1_metadata;
        private: static const ::bond::Metadata s_st1_metadata;
        private: static const ::bond::Metadata s_na_metadata;

        public: struct var
        {
            // l
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::test::List<bool>,
                &foo<_Alloc>::l,
                &s_l_metadata
            > {}  l;
        
            // v
            typedef struct : ::bond::reflection::FieldTemplate<
                1,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::test::Vector<bool>,
                &foo<_Alloc>::v,
                &s_v_metadata
            > {}  v;
        
            // s
            typedef struct : ::bond::reflection::FieldTemplate<
                2,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::test::Set<bool>,
                &foo<_Alloc>::s,
                &s_s_metadata
            > {}  s;
        
            // m
            typedef struct : ::bond::reflection::FieldTemplate<
                3,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::test::Map< ::test::String, bool>,
                &foo<_Alloc>::m,
                &s_m_metadata
            > {}  m;
        
            // st
            typedef struct : ::bond::reflection::FieldTemplate<
                4,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::test::String,
                &foo<_Alloc>::st,
                &s_st_metadata
            > {}  st;
        
            // d
            typedef struct : ::bond::reflection::FieldTemplate<
                5,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::test::String,
                &foo<_Alloc>::d,
                &s_d_metadata
            > {}  d;
        
            // l1
            typedef struct : ::bond::reflection::FieldTemplate<
                10,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::bond::maybe< ::test::List<bool> >,
                &foo<_Alloc>::l1,
                &s_l1_metadata
            > {}  l1;
        
            // v1
            typedef struct : ::bond::reflection::FieldTemplate<
                11,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::bond::maybe< ::test::Vector<bool> >,
                &foo<_Alloc>::v1,
                &s_v1_metadata
            > {}  v1;
        
            // s1
            typedef struct : ::bond::reflection::FieldTemplate<
                12,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::bond::maybe< ::test::Set<bool> >,
                &foo<_Alloc>::s1,
                &s_s1_metadata
            > {}  s1;
        
            // m1
            typedef struct : ::bond::reflection::FieldTemplate<
                13,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::bond::maybe< ::test::Map< ::test::String, bool> >,
                &foo<_Alloc>::m1,
                &s_m1_metadata
            > {}  m1;
        
            // st1
            typedef struct : ::bond::reflection::FieldTemplate<
                14,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::bond::maybe< ::test::String>,
                &foo<_Alloc>::st1,
                &s_st1_metadata
            > {}  st1;
        
            // na
            typedef struct : ::bond::reflection::FieldTemplate<
                15,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                ::test::NestedAliases,
                &foo<_Alloc>::na,
                &s_na_metadata
            > {}  na;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::na>::type fields1;
        private: typedef typename boost::mpl::push_front<fields1, typename var::st1>::type fields2;
        private: typedef typename boost::mpl::push_front<fields2, typename var::m1>::type fields3;
        private: typedef typename boost::mpl::push_front<fields3, typename var::s1>::type fields4;
        private: typedef typename boost::mpl::push_front<fields4, typename var::v1>::type fields5;
        private: typedef typename boost::mpl::push_front<fields5, typename var::l1>::type fields6;
        private: typedef typename boost::mpl::push_front<fields6, typename var::d>::type fields7;
        private: typedef typename boost::mpl::push_front<fields7, typename var::st>::type fields8;
        private: typedef typename boost::mpl::push_front<fields8, typename var::m>::type fields9;
        private: typedef typename boost::mpl::push_front<fields9, typename var::s>::type fields10;
        private: typedef typename boost::mpl::push_front<fields10, typename var::v>::type fields11;
        private: typedef typename boost::mpl::push_front<fields11, typename var::l>::type fields12;

        public: typedef typename fields12::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_l_metadata;
            (void)s_v_metadata;
            (void)s_s_metadata;
            (void)s_m_metadata;
            (void)s_st_metadata;
            (void)s_d_metadata;
            (void)s_l1_metadata;
            (void)s_v1_metadata;
            (void)s_s1_metadata;
            (void)s_m1_metadata;
            (void)s_st1_metadata;
            (void)s_na_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("foo", "test.foo",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::metadata
        = foo<_Alloc>::Schema::GetMetadata();
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_l_metadata
        = ::bond::reflection::MetadataInit("l");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_v_metadata
        = ::bond::reflection::MetadataInit("v");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_s_metadata
        = ::bond::reflection::MetadataInit("s");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_m_metadata
        = ::bond::reflection::MetadataInit("m");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_st_metadata
        = ::bond::reflection::MetadataInit("st");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_d_metadata
        = ::bond::reflection::MetadataInit("foo", "d");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_l1_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "l1");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_v1_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "v1");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_s1_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "s1");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_m1_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "m1");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_st1_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "st1");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_na_metadata
        = ::bond::reflection::MetadataInit("na");

    //
    // withFoo
    //
    template <typename _Alloc>
    struct withFoo<_Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_f_metadata;
        private: static const ::bond::Metadata s_f1_metadata;

        public: struct var
        {
            // f
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                withFoo<_Alloc>,
                ::test::TheFoo,
                &withFoo<_Alloc>::f,
                &s_f_metadata
            > {}  f;
        
            // f1
            typedef struct : ::bond::reflection::FieldTemplate<
                1,
                ::bond::reflection::optional_field_modifier,
                withFoo<_Alloc>,
                ::test::foo,
                &withFoo<_Alloc>::f1,
                &s_f1_metadata
            > {}  f1;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::f1>::type fields1;
        private: typedef typename boost::mpl::push_front<fields1, typename var::f>::type fields2;

        public: typedef typename fields2::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_f_metadata;
            (void)s_f1_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("withFoo", "test.withFoo",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <typename _Alloc>
    const ::bond::Metadata withFoo<_Alloc>::Schema::metadata
        = withFoo<_Alloc>::Schema::GetMetadata();
    
    template <typename _Alloc>
    const ::bond::Metadata withFoo<_Alloc>::Schema::s_f_metadata
        = ::bond::reflection::MetadataInit("f");
    
    template <typename _Alloc>
    const ::bond::Metadata withFoo<_Alloc>::Schema::s_f1_metadata
        = ::bond::reflection::MetadataInit("f1");

    
} // namespace test
