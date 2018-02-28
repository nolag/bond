
#pragma once

#include "maybe_blob_types.h"
#include <bond/core/reflection.h>

namespace tests
{
    //
    // Foo
    //
    template <template<typename> typename _Alloc>
    struct Foo<typename _Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_b_metadata;

        public: struct var
        {
            // b
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                Foo<typename _Alloc>,
                ::bond::maybe< ::bond::blob>,
                &Foo<typename _Alloc>::b,
                &s_b_metadata
            > {}  b;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::b>::type fields1;

        public: typedef typename fields1::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_b_metadata;
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
    const ::bond::Metadata Foo<typename _Alloc>::Schema::s_b_metadata
        = ::bond::reflection::MetadataInit(::bond::nothing, "b");

    
} // namespace tests
