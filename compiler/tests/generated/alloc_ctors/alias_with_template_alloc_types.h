
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



namespace test
{
    
    struct foo
    {
        std::list<bool, typename std::allocator_traits<arena>::template rebind_alloc<bool> > l;
        std::vector<bool, typename std::allocator_traits<arena>::template rebind_alloc<bool> > v;
        std::set<bool, std::less<bool>, typename std::allocator_traits<arena>::template rebind_alloc<bool> > s;
        std::map<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, bool, std::less<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > >, typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, bool> > > m;
        std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > st;
        std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > d;
        ::bond::maybe<std::list<bool, typename std::allocator_traits<arena>::template rebind_alloc<bool> > > l1;
        ::bond::maybe<std::vector<bool, typename std::allocator_traits<arena>::template rebind_alloc<bool> > > v1;
        ::bond::maybe<std::set<bool, std::less<bool>, typename std::allocator_traits<arena>::template rebind_alloc<bool> > > s1;
        ::bond::maybe<std::map<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, bool, std::less<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > >, typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, bool> > > > m1;
        ::bond::maybe<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > > st1;
        std::set<std::list<std::map<int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, std::less<int32_t>, typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > > > >, typename std::allocator_traits<arena>::template rebind_alloc<std::map<int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, std::less<int32_t>, typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > > > > > >, std::less<std::list<std::map<int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, std::less<int32_t>, typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > > > >, typename std::allocator_traits<arena>::template rebind_alloc<std::map<int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, std::less<int32_t>, typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > > > > > > >, typename std::allocator_traits<arena>::template rebind_alloc<std::list<std::map<int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, std::less<int32_t>, typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > > > >, typename std::allocator_traits<arena>::template rebind_alloc<std::map<int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> >, std::less<int32_t>, typename std::allocator_traits<arena>::template rebind_alloc<std::pair<const int32_t, std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<arena>::template rebind_alloc<char> > > > > > > > > na;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        foo(_bond_vc12_ctor_workaround_ = {})
          : d("foo")
        {
        }

        
        // Compiler generated copy ctor OK
        foo(const foo&) = default;

        foo(const foo& other, const arena& allocator)
          : l(other.l, allocator),
            v(other.v, allocator),
            s(other.s, allocator),
            m(other.m, allocator),
            st(other.st, allocator),
            d(other.d, allocator),
            l1(other.l1, allocator),
            v1(other.v1, allocator),
            s1(other.s1, allocator),
            m1(other.m1, allocator),
            st1(other.st1, allocator),
            na(other.na, allocator)
        {
        }
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        foo(foo&& other)
          : l(std::move(other.l)),
            v(std::move(other.v)),
            s(std::move(other.s)),
            m(std::move(other.m)),
            st(std::move(other.st)),
            d(std::move(other.d)),
            l1(std::move(other.l1)),
            v1(std::move(other.v1)),
            s1(std::move(other.s1)),
            m1(std::move(other.m1)),
            st1(std::move(other.st1)),
            na(std::move(other.na))
        {
        }
#else
        foo(foo&&) = default;
#endif

        foo(foo&& other, const arena& allocator)
          : l(std::move(other.l), allocator),
            v(std::move(other.v), allocator),
            s(std::move(other.s), allocator),
            m(std::move(other.m), allocator),
            st(std::move(other.st), allocator),
            d(std::move(other.d), allocator),
            l1(std::move(other.l1), allocator),
            v1(std::move(other.v1), allocator),
            s1(std::move(other.s1), allocator),
            m1(std::move(other.m1), allocator),
            st1(std::move(other.st1), allocator),
            na(std::move(other.na), allocator)
        {
        }
        
        explicit
        foo(const arena& allocator)
          : l(allocator),
            v(allocator),
            s(allocator),
            m(allocator),
            st(allocator),
            d("foo", allocator),
            l1(allocator),
            v1(allocator),
            s1(allocator),
            m1(allocator),
            st1(allocator),
            na(allocator)
        {
        }
        
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        foo& operator=(foo other)
        {
            other.swap(*this);
            return *this;
        }
#else
        // Compiler generated operator= OK
        foo& operator=(const foo&) = default;
        foo& operator=(foo&&) = default;
#endif

        bool operator==(const foo& other) const
        {
            return true
                && (l == other.l)
                && (v == other.v)
                && (s == other.s)
                && (m == other.m)
                && (st == other.st)
                && (d == other.d)
                && (l1 == other.l1)
                && (v1 == other.v1)
                && (s1 == other.s1)
                && (m1 == other.m1)
                && (st1 == other.st1)
                && (na == other.na);
        }

        bool operator!=(const foo& other) const
        {
            return !(*this == other);
        }

        void swap(foo& other)
        {
            using std::swap;
            swap(l, other.l);
            swap(v, other.v);
            swap(s, other.s);
            swap(m, other.m);
            swap(st, other.st);
            swap(d, other.d);
            swap(l1, other.l1);
            swap(v1, other.v1);
            swap(s1, other.s1);
            swap(m1, other.m1);
            swap(st1, other.st1);
            swap(na, other.na);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
        }
    };

    inline void swap(::test::foo& left, ::test::foo& right)
    {
        left.swap(right);
    }

    
    struct withFoo
    {
        ::test::foo f;
        ::test::foo f1;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        withFoo(_bond_vc12_ctor_workaround_ = {})
        {
        }

        
        // Compiler generated copy ctor OK
        withFoo(const withFoo&) = default;

        withFoo(const withFoo& other, const arena& allocator)
          : f(other.f, allocator),
            f1(other.f1, allocator)
        {
        }
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        withFoo(withFoo&& other)
          : f(std::move(other.f)),
            f1(std::move(other.f1))
        {
        }
#else
        withFoo(withFoo&&) = default;
#endif

        withFoo(withFoo&& other, const arena& allocator)
          : f(std::move(other.f), allocator),
            f1(std::move(other.f1), allocator)
        {
        }
        
        explicit
        withFoo(const arena& allocator)
          : f(allocator),
            f1(allocator)
        {
        }
        
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        withFoo& operator=(withFoo other)
        {
            other.swap(*this);
            return *this;
        }
#else
        // Compiler generated operator= OK
        withFoo& operator=(const withFoo&) = default;
        withFoo& operator=(withFoo&&) = default;
#endif

        bool operator==(const withFoo& other) const
        {
            return true
                && (f == other.f)
                && (f1 == other.f1);
        }

        bool operator!=(const withFoo& other) const
        {
            return !(*this == other);
        }

        void swap(withFoo& other)
        {
            using std::swap;
            swap(f, other.f);
            swap(f1, other.f1);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
        }
    };

    inline void swap(::test::withFoo& left, ::test::withFoo& right)
    {
        left.swap(right);
    }
} // namespace test

namespace std
{
    template <typename _Alloc>
    struct uses_allocator< ::test::foo, _Alloc>
        : is_convertible<_Alloc, arena>
    {};

    template <typename _Alloc>
    struct uses_allocator< ::test::withFoo, _Alloc>
        : is_convertible<_Alloc, arena>
    {};
}

