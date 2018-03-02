
#pragma once

#include "alias_key_types.h"
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
        
        private: static const ::bond::Metadata s_m_metadata;
        private: static const ::bond::Metadata s_s_metadata;

        public: struct var
        {
            // m
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                std::map< ::test::String, ::test::Int, std::less< ::test::String>, typename std::allocator_traits<_Alloc>::template rebind_alloc<std::pair<const ::test::String, ::test::Int> > >,
                &foo<_Alloc>::m,
                &s_m_metadata
            > {}  m;
        
            // s
            typedef struct : ::bond::reflection::FieldTemplate<
                1,
                ::bond::reflection::optional_field_modifier,
                foo<_Alloc>,
                std::set< ::test::Int, std::less< ::test::Int>, typename std::allocator_traits<_Alloc>::template rebind_alloc< ::test::Int> >,
                &foo<_Alloc>::s,
                &s_s_metadata
            > {}  s;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::s>::type fields1;
        private: typedef typename boost::mpl::push_front<fields1, typename var::m>::type fields2;

        public: typedef typename fields2::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_m_metadata;
            (void)s_s_metadata;
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
    const ::bond::Metadata foo<_Alloc>::Schema::s_m_metadata
        = ::bond::reflection::MetadataInit("m");
    
    template <typename _Alloc>
    const ::bond::Metadata foo<_Alloc>::Schema::s_s_metadata
        = ::bond::reflection::MetadataInit("s");

    
} // namespace test
