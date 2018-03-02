
#pragma once

#include "inheritance_types.h"
#include <bond/core/reflection.h>

namespace tests
{
    //
    // Base
    //
    template <class _Alloc>
    struct Base<_Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_x_metadata;

        public: struct var
        {
            // x
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                Base<_Alloc>,
                int32_t,
                &Base<_Alloc>::x,
                &s_x_metadata
            > {}  x;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::x>::type fields1;

        public: typedef typename fields1::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_x_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("Base", "tests.Base",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <class _Alloc>
    const ::bond::Metadata Base<_Alloc>::Schema::metadata
        = Base<_Alloc>::Schema::GetMetadata();
    
    template <class _Alloc>
    const ::bond::Metadata Base<_Alloc>::Schema::s_x_metadata
        = ::bond::reflection::MetadataInit("x");

    //
    // Foo
    //
    template <class _Alloc>
    struct Foo<_Alloc>::Schema
    {
        typedef ::tests::Base<_Alloc> base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_x_metadata;

        public: struct var
        {
            // x
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                Foo<_Alloc>,
                int32_t,
                &Foo<_Alloc>::x,
                &s_x_metadata
            > {}  x;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::x>::type fields1;

        public: typedef typename fields1::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_x_metadata;
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
    const ::bond::Metadata Foo<_Alloc>::Schema::s_x_metadata
        = ::bond::reflection::MetadataInit("x");

    
} // namespace tests
