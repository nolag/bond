
#pragma once

#include "complex_types_types.h"
#include <bond/core/reflection.h>

namespace tests
{
    //
    // Foo
    //
    template <typename _Alloc>
    struct Foo<_Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        

        public: struct var
        {};

        private: typedef boost::mpl::list<> fields0;
        

        public: typedef typename fields0::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("Foo", "tests.Foo",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <typename _Alloc>
    const ::bond::Metadata Foo<_Alloc>::Schema::metadata
        = Foo<_Alloc>::Schema::GetMetadata();

    //
    // ComplexTypes
    //
    template <typename _Alloc>
    struct ComplexTypes<_Alloc>::Schema
    {
        typedef ::bond::no_base base;

        static const ::bond::Metadata metadata;
        
        private: static const ::bond::Metadata s_li8_metadata;
        private: static const ::bond::Metadata s_sb_metadata;
        private: static const ::bond::Metadata s_vb_metadata;
        private: static const ::bond::Metadata s_nf_metadata;
        private: static const ::bond::Metadata s_msws_metadata;
        private: static const ::bond::Metadata s_bfoo_metadata;
        private: static const ::bond::Metadata s_m_metadata;

        public: struct var
        {
            // li8
            typedef struct : ::bond::reflection::FieldTemplate<
                0,
                ::bond::reflection::optional_field_modifier,
                ComplexTypes<_Alloc>,
                std::list<int8_t, typename std::allocator_traits<_Alloc>::template rebind_alloc<int8_t> >,
                &ComplexTypes<_Alloc>::li8,
                &s_li8_metadata
            > {}  li8;
        
            // sb
            typedef struct : ::bond::reflection::FieldTemplate<
                1,
                ::bond::reflection::optional_field_modifier,
                ComplexTypes<_Alloc>,
                std::set<bool, std::less<bool>, typename std::allocator_traits<_Alloc>::template rebind_alloc<bool> >,
                &ComplexTypes<_Alloc>::sb,
                &s_sb_metadata
            > {}  sb;
        
            // vb
            typedef struct : ::bond::reflection::FieldTemplate<
                2,
                ::bond::reflection::optional_field_modifier,
                ComplexTypes<_Alloc>,
                std::vector< ::bond::blob, typename std::allocator_traits<_Alloc>::template rebind_alloc< ::bond::blob> >,
                &ComplexTypes<_Alloc>::vb,
                &s_vb_metadata
            > {}  vb;
        
            // nf
            typedef struct : ::bond::reflection::FieldTemplate<
                3,
                ::bond::reflection::optional_field_modifier,
                ComplexTypes<_Alloc>,
                ::bond::nullable<float>,
                &ComplexTypes<_Alloc>::nf,
                &s_nf_metadata
            > {}  nf;
        
            // msws
            typedef struct : ::bond::reflection::FieldTemplate<
                4,
                ::bond::reflection::optional_field_modifier,
                ComplexTypes<_Alloc>,
                std::map<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<_Alloc>::template rebind_alloc<char> >, std::basic_string<wchar_t, std::char_traits<wchar_t>, typename std::allocator_traits<_Alloc>::template rebind_alloc<wchar_t> >, std::less<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<_Alloc>::template rebind_alloc<char> > >, typename std::allocator_traits<_Alloc>::template rebind_alloc<std::pair<const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<_Alloc>::template rebind_alloc<char> >, std::basic_string<wchar_t, std::char_traits<wchar_t>, typename std::allocator_traits<_Alloc>::template rebind_alloc<wchar_t> > > > >,
                &ComplexTypes<_Alloc>::msws,
                &s_msws_metadata
            > {}  msws;
        
            // bfoo
            typedef struct : ::bond::reflection::FieldTemplate<
                5,
                ::bond::reflection::optional_field_modifier,
                ComplexTypes<_Alloc>,
                ::bond::bonded< ::tests::Foo<_Alloc> >,
                &ComplexTypes<_Alloc>::bfoo,
                &s_bfoo_metadata
            > {}  bfoo;
        
            // m
            typedef struct : ::bond::reflection::FieldTemplate<
                6,
                ::bond::reflection::optional_field_modifier,
                ComplexTypes<_Alloc>,
                std::map<double, std::list<std::vector< ::bond::nullable< ::bond::bonded< ::tests::Bar<_Alloc> > >, typename std::allocator_traits<_Alloc>::template rebind_alloc< ::bond::nullable< ::bond::bonded< ::tests::Bar<_Alloc> > > > >, typename std::allocator_traits<_Alloc>::template rebind_alloc<std::vector< ::bond::nullable< ::bond::bonded< ::tests::Bar<_Alloc> > >, typename std::allocator_traits<_Alloc>::template rebind_alloc< ::bond::nullable< ::bond::bonded< ::tests::Bar<_Alloc> > > > > > >, std::less<double>, typename std::allocator_traits<_Alloc>::template rebind_alloc<std::pair<const double, std::list<std::vector< ::bond::nullable< ::bond::bonded< ::tests::Bar<_Alloc> > >, typename std::allocator_traits<_Alloc>::template rebind_alloc< ::bond::nullable< ::bond::bonded< ::tests::Bar<_Alloc> > > > >, typename std::allocator_traits<_Alloc>::template rebind_alloc<std::vector< ::bond::nullable< ::bond::bonded< ::tests::Bar<_Alloc> > >, typename std::allocator_traits<_Alloc>::template rebind_alloc< ::bond::nullable< ::bond::bonded< ::tests::Bar<_Alloc> > > > > > > > > >,
                &ComplexTypes<_Alloc>::m,
                &s_m_metadata
            > {}  m;
        };

        private: typedef boost::mpl::list<> fields0;
        private: typedef typename boost::mpl::push_front<fields0, typename var::m>::type fields1;
        private: typedef typename boost::mpl::push_front<fields1, typename var::bfoo>::type fields2;
        private: typedef typename boost::mpl::push_front<fields2, typename var::msws>::type fields3;
        private: typedef typename boost::mpl::push_front<fields3, typename var::nf>::type fields4;
        private: typedef typename boost::mpl::push_front<fields4, typename var::vb>::type fields5;
        private: typedef typename boost::mpl::push_front<fields5, typename var::sb>::type fields6;
        private: typedef typename boost::mpl::push_front<fields6, typename var::li8>::type fields7;

        public: typedef typename fields7::type fields;
        
        Schema()
        {
            // Force instantiation of template statics
            (void)metadata;
            (void)s_li8_metadata;
            (void)s_sb_metadata;
            (void)s_vb_metadata;
            (void)s_nf_metadata;
            (void)s_msws_metadata;
            (void)s_bfoo_metadata;
            (void)s_m_metadata;
        }
        
        static ::bond::Metadata GetMetadata()
        {
            return ::bond::reflection::MetadataInit("ComplexTypes", "tests.ComplexTypes",
                ::bond::reflection::Attributes()
            );
        }
    };
    
    template <typename _Alloc>
    const ::bond::Metadata ComplexTypes<_Alloc>::Schema::metadata
        = ComplexTypes<_Alloc>::Schema::GetMetadata();
    
    template <typename _Alloc>
    const ::bond::Metadata ComplexTypes<_Alloc>::Schema::s_li8_metadata
        = ::bond::reflection::MetadataInit("li8");
    
    template <typename _Alloc>
    const ::bond::Metadata ComplexTypes<_Alloc>::Schema::s_sb_metadata
        = ::bond::reflection::MetadataInit("sb");
    
    template <typename _Alloc>
    const ::bond::Metadata ComplexTypes<_Alloc>::Schema::s_vb_metadata
        = ::bond::reflection::MetadataInit("vb");
    
    template <typename _Alloc>
    const ::bond::Metadata ComplexTypes<_Alloc>::Schema::s_nf_metadata
        = ::bond::reflection::MetadataInit("nf");
    
    template <typename _Alloc>
    const ::bond::Metadata ComplexTypes<_Alloc>::Schema::s_msws_metadata
        = ::bond::reflection::MetadataInit("msws");
    
    template <typename _Alloc>
    const ::bond::Metadata ComplexTypes<_Alloc>::Schema::s_bfoo_metadata
        = ::bond::reflection::MetadataInit("bfoo");
    
    template <typename _Alloc>
    const ::bond::Metadata ComplexTypes<_Alloc>::Schema::s_m_metadata
        = ::bond::reflection::MetadataInit("m");

    
} // namespace tests
