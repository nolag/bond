
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
#include <scoped_allocator>
#include <memory>


namespace tests
{
    
    namespace _bond_enumerators
    {
    namespace Enum
    {
        enum Enum
        {
            Value1
        };
        
        inline BOND_CONSTEXPR const char* GetTypeName(enum Enum)
        {
            return "Enum";
        }

        inline BOND_CONSTEXPR const char* GetTypeName(enum Enum, const ::bond::qualified_name_tag&)
        {
            return "tests.Enum";
        }

#if defined(_MSC_VER) && (_MSC_VER < 1900) // Versions of MSVC prior to 1900 do not support magic statics
        extern const std::map<enum Enum, std::string> _value_to_name_Enum;

        inline const std::map<enum Enum, std::string>& GetValueToNameMap(enum Enum)
        {
            return _value_to_name_Enum;
        }

        extern const std::map<std::string, enum Enum> _name_to_value_Enum;

        inline const std::map<std::string, enum Enum>& GetNameToValueMap(enum Enum)
        {
            return _name_to_value_Enum;
        }
#else
        template <typename Map = std::map<enum Enum, std::string> >
        inline const Map& GetValueToNameMap(enum Enum, ::bond::detail::mpl::identity<Map> = {})
        {
            static const Map s_valueToNameMap
                {
                    { Value1, "Value1" }
                };
            return s_valueToNameMap;
        }

        template <typename Map = std::map<std::string, enum Enum> >
        inline const Map& GetNameToValueMap(enum Enum, ::bond::detail::mpl::identity<Map> = {})
        {
            static const Map s_nameToValueMap
                {
                    { "Value1", Value1 }
                };
            return s_nameToValueMap;
        }
#endif
        const std::string& ToString(enum Enum value);

        void FromString(const std::string& name, enum Enum& value);

        bool ToEnum(enum Enum& value, const std::string& name);

        bool FromEnum(std::string& name, enum Enum value);

    } // namespace Enum
    } // namespace _bond_enumerators

    using namespace _bond_enumerators::Enum;
    

    
    template <typename _Alloc>
    struct Foo
    {
        std::basic_string<char, std::char_traits<char>, std::scoped_allocator_adaptor<typename std::allocator_traits<_Alloc>::template rebind_alloc<char> > > f;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        Foo(_bond_vc12_ctor_workaround_ = {})
        {
        }

        
        // Compiler generated copy ctor OK
        Foo(const Foo&) = default;
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        Foo(Foo&& other)
          : f(std::move(other.f))
        {
        }
#else
        Foo(Foo&&) = default;
#endif
        
        explicit
        Foo(const _Alloc& allocator)
          : f(allocator)
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
                && (f == other.f);
        }

        bool operator!=(const Foo& other) const
        {
            return !(*this == other);
        }

        void swap(Foo& other)
        {
            using std::swap;
            swap(f, other.f);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
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
    struct uses_allocator<::tests::Foo<_Alloc>, _AllocTo>
        : is_convertible<_AllocTo, _Alloc>
    {};
}

