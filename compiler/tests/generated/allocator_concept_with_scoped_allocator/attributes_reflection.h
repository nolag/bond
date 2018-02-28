
#pragma once

#include "attributes_types.h"
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
        
        private: static const ::bond::Metadata s_f_metadata;

        public: struct var
        {
            // f
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                Foo<typename _Alloc>,
                std::basic_string<char, std::char_traits<char>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<char> > >,
                &Foo<typename _Alloc>::f,
                &s_f_metadata
            > {}  f;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::f>::type fields1;

        public: typedef typename fields1::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_f_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("Foo", "tests.Foo",
                {
                    { "StructAttribute1", "one" },
                    { "StructAttribute2", "two" }
                }
            );
        }
    };
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata Foo<typename _Alloc>::Schema::metadata
        = Foo<typename _Alloc>::Schema::GetMetadata();
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata Foo<typename _Alloc>::Schema::s_f_metadata
        = ::bond::reflection::MetadataInit("f", ::bond::reflection::optional_field_modifier::value,
                {
                    { "FieldAttribute1", "one" },
                    { "FieldAttribute2", "two" }
                });

    
} // namespace tests
