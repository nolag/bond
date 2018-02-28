
#pragma once

#include "inheritance_types.h"
#include <bond/core/reflection.h>

namespace tests
{
    //
    // Base
    //
    template <template<typename> typename _Alloc>
    struct Base<typename _Alloc>::Schema
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
                Base<typename _Alloc>,
                int32_t,
                &Base<typename _Alloc>::x,
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
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata Base<typename _Alloc>::Schema::metadata
        = Base<typename _Alloc>::Schema::GetMetadata();
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata Base<typename _Alloc>::Schema::s_x_metadata
        = ::bond::reflection::MetadataInit("x");

    //
    // Foo
    //
    template <template<typename> typename _Alloc>
    struct Foo<typename _Alloc>::Schema
    {
        typedef ::tests::Base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_x_metadata;

        public: struct var
        {
            // x
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                Foo<typename _Alloc>,
                int32_t,
                &Foo<typename _Alloc>::x,
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
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata Foo<typename _Alloc>::Schema::metadata
        = Foo<typename _Alloc>::Schema::GetMetadata();
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata Foo<typename _Alloc>::Schema::s_x_metadata
        = ::bond::reflection::MetadataInit("x");

    
} // namespace tests
