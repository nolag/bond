
#pragma once

#include <bond/core/bond_version.h>

#if BOND_VERSION < 0x0700
#error This file was generated by a newer version of the Bond compiler and is incompatible with your version of the Bond library.
#endif

#if BOND_MIN_CODEGEN_VERSION > 0x0b00
#error This file was generated by an older version of the Bond compiler and is incompatible with your version of the Bond library.
#endif

#include <bond/core/config.h>
#include <bond/core/containers.h>
#include <bond/core/nullable.h>
#include <bond/core/bonded.h>
#include <bond/core/blob.h>
#include <scoped_allocator>
#include <memory>


namespace tests
{
    
    template <template<typename> class _Alloc=std::allocator>
    struct Foo
    {
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        Foo(_bond_vc12_ctor_workaround_ = {})
        {
        }
        
        // Compiler generated copy ctor OK
        Foo(const Foo&) = default;
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Foo(Foo&&)
        {
        }
#else
        Foo(Foo&&) = default;
#endif
        
        explicit
        Foo(const _Alloc<::tests::Foo<_Alloc>>& allocator)
        {
        }
        
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Foo& operator=(Foo other)
        {
            other.swap(*this);
            return *this;
        }
#else
        // Compiler generated operator= OK
        Foo& operator=(const Foo&) = default;
        Foo& operator=(Foo&&) = default;
#endif

        bool operator==(const Foo&) const
        {
            return true;
        }

        bool operator!=(const Foo& other) const
        {
            return !(*this == other);
        }

        void swap(Foo&)
        {
            using std::swap;
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
        }
    };

    template <template<typename> class _Alloc=std::allocator>
    inline void swap(::tests::Foo<_Alloc>& left, ::tests::Foo<_Alloc>& right)
    {
        left.swap(right);
    }

    template <template<typename> class _Alloc>
    struct Bar;

    
    template <template<typename> class _Alloc=std::allocator>
    struct ComplexTypes
    {
        std::list<int8_t, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<int8_t> > > li8;
        std::set<bool, std::less<bool>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<bool> > > sb;
        std::vector< ::bond::blob, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc< ::bond::blob> > > vb;
        ::bond::nullable<float> nf;
        std::map<std::basic_string<char, std::char_traits<char>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<char> > >, std::basic_string<wchar_t, std::char_traits<wchar_t>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<wchar_t> > >, std::less<std::basic_string<char, std::char_traits<char>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<char> > > >, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const std::basic_string<char, std::char_traits<char>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<char> > >, std::basic_string<wchar_t, std::char_traits<wchar_t>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<wchar_t> > > > > > > msws;
        ::bond::bonded< ::tests::Foo> bfoo;
        std::map<double, std::list<std::vector< ::bond::nullable< ::bond::bonded< ::tests::Bar> >, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc< ::bond::nullable< ::bond::bonded< ::tests::Bar> > > > >, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<std::vector< ::bond::nullable< ::bond::bonded< ::tests::Bar> >, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc< ::bond::nullable< ::bond::bonded< ::tests::Bar> > > > > > > >, std::less<double>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const double, std::list<std::vector< ::bond::nullable< ::bond::bonded< ::tests::Bar> >, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc< ::bond::nullable< ::bond::bonded< ::tests::Bar> > > > >, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<std::vector< ::bond::nullable< ::bond::bonded< ::tests::Bar> >, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc< ::bond::nullable< ::bond::bonded< ::tests::Bar> > > > > > > > > > > > m;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        ComplexTypes(_bond_vc12_ctor_workaround_ = {})
        {
        }
        
        // Compiler generated copy ctor OK
        ComplexTypes(const ComplexTypes&) = default;
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        ComplexTypes(ComplexTypes&& other)
          : li8(std::move(other.li8)),
            sb(std::move(other.sb)),
            vb(std::move(other.vb)),
            nf(std::move(other.nf)),
            msws(std::move(other.msws)),
            bfoo(std::move(other.bfoo)),
            m(std::move(other.m))
        {
        }
#else
        ComplexTypes(ComplexTypes&&) = default;
#endif
        
        explicit
        ComplexTypes(const _Alloc<::tests::ComplexTypes<_Alloc>>& allocator)
          : li8(allocator),
            sb(allocator),
            vb(allocator),
            nf(),
            msws(allocator),
            m(allocator)
        {
        }
        
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        ComplexTypes& operator=(ComplexTypes other)
        {
            other.swap(*this);
            return *this;
        }
#else
        // Compiler generated operator= OK
        ComplexTypes& operator=(const ComplexTypes&) = default;
        ComplexTypes& operator=(ComplexTypes&&) = default;
#endif

        bool operator==(const ComplexTypes& other) const
        {
            return true
                && (li8 == other.li8)
                && (sb == other.sb)
                && (vb == other.vb)
                && (nf == other.nf)
                && (msws == other.msws)
                && (bfoo == other.bfoo)
                && (m == other.m);
        }

        bool operator!=(const ComplexTypes& other) const
        {
            return !(*this == other);
        }

        void swap(ComplexTypes& other)
        {
            using std::swap;
            swap(li8, other.li8);
            swap(sb, other.sb);
            swap(vb, other.vb);
            swap(nf, other.nf);
            swap(msws, other.msws);
            swap(bfoo, other.bfoo);
            swap(m, other.m);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
        }
    };

    template <template<typename> class _Alloc=std::allocator>
    inline void swap(::tests::ComplexTypes<_Alloc>& left, ::tests::ComplexTypes<_Alloc>& right)
    {
        left.swap(right);
    }
} // namespace tests

namespace std
{
    template<typename _AllocTo,  template<typename> class _Alloc>
        struct uses_allocator<::tests::Foo<_Alloc>, _AllocTo>
        : is_convertible<_AllocTo, _Alloc<::tests::Foo<_Alloc>>>
    {};

    template<typename _AllocTo,  template<typename> class _Alloc>
        struct uses_allocator<::tests::ComplexTypes<_Alloc>, _AllocTo>
        : is_convertible<_AllocTo, _Alloc<::tests::ComplexTypes<_Alloc>>>
    {};
}


