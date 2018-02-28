
#pragma once

#include "field_modifiers_types.h"
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
        
        private: static const ::bond::Metadata s_o_metadata;
        private: static const ::bond::Metadata s_r_metadata;
        private: static const ::bond::Metadata s_ro_metadata;

        public: struct var
        {
            // o
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                Foo<typename _Alloc>,
                bool,
                &Foo<typename _Alloc>::o,
                &s_o_metadata
            > {}  o;
        
            // r
            typedef struct : ::bond::reflection::FieldTemplate<
                1,
                ::bond::reflection::required_field_modifier,
                Foo<typename _Alloc>,
                int16_t,
                &Foo<typename _Alloc>::r,
                &s_r_metadata
            > {}  r;
        
            // ro
            typedef struct : ::bond::reflection::FieldTemplate<
                2,
                ::bond::reflection::required_optional_field_modifier,
                Foo<typename _Alloc>,
                double,
                &Foo<typename _Alloc>::ro,
                &s_ro_metadata
            > {}  ro;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::ro>::type fields1;
        private: typedef typename boost::mpl::push_front<fields1, typename var::r>::type fields2;
        private: typedef typename boost::mpl::push_front<fields2, typename var::o>::type fields3;

        public: typedef typename fields3::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_o_metadata;
            (void)s_r_metadata;
            (void)s_ro_metadata;
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
    const ::bond::Metadata Foo<typename _Alloc>::Schema::s_o_metadata
        = ::bond::reflection::MetadataInit("o");
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata Foo<typename _Alloc>::Schema::s_r_metadata
        = ::bond::reflection::MetadataInit("r", ::bond::reflection::required_field_modifier::value,
                ::bond::reflection::Attributes());
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata Foo<typename _Alloc>::Schema::s_ro_metadata
        = ::bond::reflection::MetadataInit("ro", ::bond::reflection::required_optional_field_modifier::value,
                ::bond::reflection::Attributes());

    
} // namespace tests
