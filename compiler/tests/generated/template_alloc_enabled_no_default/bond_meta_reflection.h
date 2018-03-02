
#pragma once

#include "bond_meta_types.h"
#include <bond/core/reflection.h>

namespace deprecated
{
namespace bondmeta
{
    //
    // HasMetaFields
    //
    template <class _Alloc>
    struct HasMetaFields<_Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_full_name_metadata;
        private: static const ::bond::Metadata s_name_metadata;

        public: struct var
        {
            // full_name
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::required_optional_field_modifier,
                HasMetaFields<_Alloc>,
                std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<_Alloc>::template rebind_alloc<char> >,
                &HasMetaFields<_Alloc>::full_name,
                &s_full_name_metadata
            > {}  full_name;
        
            // name
            typedef struct : ::bond::reflection::FieldTemplate<
                1,
                ::bond::reflection::required_optional_field_modifier,
                HasMetaFields<_Alloc>,
                std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<_Alloc>::template rebind_alloc<char> >,
                &HasMetaFields<_Alloc>::name,
                &s_name_metadata
            > {}  name;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::name>::type fields1;
        private: typedef typename boost::mpl::push_front<fields1, typename var::full_name>::type fields2;

        public: typedef typename fields2::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_full_name_metadata;
            (void)s_name_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("HasMetaFields", "deprecated.bondmeta.HasMetaFields",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <class _Alloc>
    const ::bond::Metadata HasMetaFields<_Alloc>::Schema::metadata
        = HasMetaFields<_Alloc>::Schema::GetMetadata();
    
    template <class _Alloc>
    const ::bond::Metadata HasMetaFields<_Alloc>::Schema::s_full_name_metadata
        = ::bond::reflection::MetadataInit("full_name");
    
    template <class _Alloc>
    const ::bond::Metadata HasMetaFields<_Alloc>::Schema::s_name_metadata
        = ::bond::reflection::MetadataInit("name");

    
} // namespace bondmeta
} // namespace deprecated
