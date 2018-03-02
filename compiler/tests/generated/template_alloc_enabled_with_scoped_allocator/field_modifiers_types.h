
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
#include <memory>


namespace tests
{
    
    template <class _Alloc>
    struct Foo
    {
        bool o;
        int16_t r;
        double ro;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        Foo(_bond_vc12_ctor_workaround_ = {})
          : o(),
            r(),
            ro()
        {
        }

        
        // Compiler generated copy ctor OK
        Foo(const Foo&) = default;
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Foo(Foo&& other)
          : o(std::move(other.o)),
            r(std::move(other.r)),
            ro(std::move(other.ro))
        {
        }
#else
        Foo(Foo&&) = default;
#endif
        
        explicit
        Foo(const _Alloc& allocator)
          : o(),
            r(),
            ro()
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

        bool operator==(const Foo& other) const
        {
            return true
                && (o == other.o)
                && (r == other.r)
                && (ro == other.ro);
        }

        bool operator!=(const Foo& other) const
        {
            return !(*this == other);
        }

        void swap(Foo& other)
        {
            using std::swap;
            swap(o, other.o);
            swap(r, other.r);
            swap(ro, other.ro);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
        }
    };

    template <class _Alloc>
    inline void swap(::tests::Foo<_Alloc>& left, ::tests::Foo<_Alloc>& right)
    {
        left.swap(right);
    }
} // namespace tests

namespace std
{
    template<typename _AllocTo, typename _Alloc>
    struct uses_allocator<::tests::Foo<_Alloc>, _AllocTo>
        : is_convertible<_AllocTo, _Alloc>
    {};
}

