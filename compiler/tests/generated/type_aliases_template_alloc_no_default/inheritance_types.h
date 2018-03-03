
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
    
    template <typename _Alloc>
    struct Base
    {
        int32_t x;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        Base(_bond_vc12_ctor_workaround_ = {})
          : x()
        {
        }

        
        // Compiler generated copy ctor OK
        Base(const Base&) = default;
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Base(Base&& other)
          : x(std::move(other.x))
        {
        }
#else
        Base(Base&&) = default;
#endif
        
        explicit
        Base(const _Alloc& allocator)
          : x()
        {
        }
        
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Base& operator=(Base other)
        {
            other.swap(*this);
            return *this;
        }
#else
        // Compiler generated operator= OK
        Base& operator=(const Base&) = default;
        Base& operator=(Base&&) = default;
#endif

        bool operator==(const Base& other) const
        {
            return true
                && (x == other.x);
        }

        bool operator!=(const Base& other) const
        {
            return !(*this == other);
        }

        void swap(Base& other)
        {
            using std::swap;
            swap(x, other.x);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
        }
    };

    template <typename _Alloc>
    inline void swap(::tests::Base<_Alloc>& left, ::tests::Base<_Alloc>& right)
    {
        left.swap(right);
    }

    
    template <typename _Alloc>
    struct Foo
      : ::tests::Base
    {
        int32_t x;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        Foo(_bond_vc12_ctor_workaround_ = {})
          : x()
        {
        }

        
        // Compiler generated copy ctor OK
        Foo(const Foo&) = default;
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Foo(Foo&& other)
          : ::tests::Base(std::move(other)),
            x(std::move(other.x))
        {
        }
#else
        Foo(Foo&&) = default;
#endif
        
        explicit
        Foo(const _Alloc& allocator)
          : ::tests::Base(allocator),
            x()
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
                && (static_cast<const ::tests::Base&>(*this) == static_cast<const ::tests::Base&>( other))
                && (x == other.x);
        }

        bool operator!=(const Foo& other) const
        {
            return !(*this == other);
        }

        void swap(Foo& other)
        {
            using std::swap;
            ::tests::Base::swap( other);
            swap(x, other.x);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*name, const char*qual_name)
        {
            ::tests::Base::InitMetadata(name, qual_name);
        }
    };

    template <typename _Alloc>
    inline void swap(::tests::Foo<_Alloc>& left, ::tests::Foo<_Alloc>& right)
    {
        left.swap(right);
    }
} // namespace tests

namespace std
{
    template<typename _AllocTo, typename _Alloc>
    struct uses_allocator<::tests::Base<_Alloc>, _AllocTo>
        : is_convertible<_AllocTo, _Alloc>
    {};

    template<typename _AllocTo, typename _Alloc>
    struct uses_allocator<::tests::Foo<_Alloc>, _AllocTo>
        : is_convertible<_AllocTo, _Alloc>
    {};
}
