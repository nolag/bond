
#pragma once

#include "aliases_types.h"
#include <bond/core/reflection.h>

namespace tests
{
    //
    // Foo
    //
    template <typename T, template<typename> typename _Alloc>
    struct Foo<T, typename _Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_aa_metadata;

        public: struct var
        {
            // aa
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                Foo<T, typename _Alloc>,
                std::vector<std::vector<T, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<T> > >, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<std::vector<T, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<T> > > > > >,
                &Foo<T, typename _Alloc>::aa,
                &s_aa_metadata
            > {}  aa;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::aa>::type fields1;

        public: typedef typename fields1::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_aa_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit<boost::mpl::list<T> >("Foo", "tests.Foo",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <typename T, template<typename> typename _Alloc>
    const ::bond::Metadata Foo<T, typename _Alloc>::Schema::metadata
        = Foo<T, typename _Alloc>::Schema::GetMetadata();
    
    template <typename T, template<typename> typename _Alloc>
    const ::bond::Metadata Foo<T, typename _Alloc>::Schema::s_aa_metadata
        = ::bond::reflection::MetadataInit("aa");

    //
    // WrappingAnEnum
    //
    template <template<typename> typename _Alloc>
    struct WrappingAnEnum<typename _Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_aWrappedEnum_metadata;

        public: struct var
        {
            // aWrappedEnum
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                WrappingAnEnum<typename _Alloc>,
                ::tests::EnumToWrap,
                &WrappingAnEnum<typename _Alloc>::aWrappedEnum,
                &s_aWrappedEnum_metadata
            > {}  aWrappedEnum;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::aWrappedEnum>::type fields1;

        public: typedef typename fields1::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_aWrappedEnum_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("WrappingAnEnum", "tests.WrappingAnEnum",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata WrappingAnEnum<typename _Alloc>::Schema::metadata
        = WrappingAnEnum<typename _Alloc>::Schema::GetMetadata();
    
    template <template<typename> typename _Alloc>
    const ::bond::Metadata WrappingAnEnum<typename _Alloc>::Schema::s_aWrappedEnum_metadata
        = ::bond::reflection::MetadataInit(::tests::_bond_enumerators::EnumToWrap::anEnumValue, "aWrappedEnum");

    
} // namespace tests
