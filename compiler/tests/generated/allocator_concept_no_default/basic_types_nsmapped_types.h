
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
#include <bond/core/blob.h>
#include <memory>


namespace nsmapped
{
    
    template <template<typename> class _Alloc=std::allocator>
    struct BasicTypes
    {
        bool _bool;
        std::basic_string<char, std::char_traits<char>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<char> > > _str;
        std::basic_string<wchar_t, std::char_traits<wchar_t>, std::scoped_allocator_adaptor<typename std::allocator_traits<arena>::template rebind_alloc<wchar_t> > > _wstr;
        uint64_t _uint64;
        uint16_t _uint16;
        uint32_t _uint32;
        uint8_t _uint8;
        int8_t _int8;
        int16_t _int16;
        int32_t _int32;
        int64_t _int64;
        double _double;
        float _float;
        ::bond::blob _blob;
        
        struct _bond_vc12_ctor_workaround_ {};
        template <int = 0> // Workaround to avoid compilation if not used
        BasicTypes(_bond_vc12_ctor_workaround_ = {})
          : _bool(),
            _uint64(),
            _uint16(),
            _uint32(),
            _uint8(),
            _int8(),
            _int16(),
            _int32(),
            _int64(),
            _double(),
            _float()
        {
        }
        
        // Compiler generated copy ctor OK
        BasicTypes(const BasicTypes&) = default;
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        BasicTypes(BasicTypes&& other)
          : _bool(std::move(other._bool)),
            _str(std::move(other._str)),
            _wstr(std::move(other._wstr)),
            _uint64(std::move(other._uint64)),
            _uint16(std::move(other._uint16)),
            _uint32(std::move(other._uint32)),
            _uint8(std::move(other._uint8)),
            _int8(std::move(other._int8)),
            _int16(std::move(other._int16)),
            _int32(std::move(other._int32)),
            _int64(std::move(other._int64)),
            _double(std::move(other._double)),
            _float(std::move(other._float)),
            _blob(std::move(other._blob))
        {
        }
#else
        BasicTypes(BasicTypes&&) = default;
#endif
        
        explicit
        BasicTypes(const _Alloc<::nsmapped::BasicTypes<_Alloc>>& allocator)
          : _bool(),
            _str(allocator),
            _wstr(allocator),
            _uint64(),
            _uint16(),
            _uint32(),
            _uint8(),
            _int8(),
            _int16(),
            _int32(),
            _int64(),
            _double(),
            _float()
        {
        }
        
        
#if defined(_MSC_VER) && (_MSC_VER < 1900)  // Versions of MSVC prior to 1900 do not support = default for move ctors
        BasicTypes& operator=(BasicTypes other)
        {
            other.swap(*this);
            return *this;
        }
#else
        // Compiler generated operator= OK
        BasicTypes& operator=(const BasicTypes&) = default;
        BasicTypes& operator=(BasicTypes&&) = default;
#endif

        bool operator==(const BasicTypes& other) const
        {
            return true
                && (_bool == other._bool)
                && (_str == other._str)
                && (_wstr == other._wstr)
                && (_uint64 == other._uint64)
                && (_uint16 == other._uint16)
                && (_uint32 == other._uint32)
                && (_uint8 == other._uint8)
                && (_int8 == other._int8)
                && (_int16 == other._int16)
                && (_int32 == other._int32)
                && (_int64 == other._int64)
                && (_double == other._double)
                && (_float == other._float)
                && (_blob == other._blob);
        }

        bool operator!=(const BasicTypes& other) const
        {
            return !(*this == other);
        }

        void swap(BasicTypes& other)
        {
            using std::swap;
            swap(_bool, other._bool);
            swap(_str, other._str);
            swap(_wstr, other._wstr);
            swap(_uint64, other._uint64);
            swap(_uint16, other._uint16);
            swap(_uint32, other._uint32);
            swap(_uint8, other._uint8);
            swap(_int8, other._int8);
            swap(_int16, other._int16);
            swap(_int32, other._int32);
            swap(_int64, other._int64);
            swap(_double, other._double);
            swap(_float, other._float);
            swap(_blob, other._blob);
        }

        struct Schema;

    protected:
        void InitMetadata(const char*, const char*)
        {
        }
    };

    template <template<typename> class _Alloc=std::allocator>
    inline void swap(::nsmapped::BasicTypes<_Alloc>& left, ::nsmapped::BasicTypes<_Alloc>& right)
    {
        left.swap(right);
    }
} // namespace nsmapped

namespace std
{
    template<typename _AllocTo,  template<typename> class _Alloc>
        struct uses_allocator<::nsmapped::BasicTypes<_Alloc>, _AllocTo>
        : is_convertible<_AllocTo, _Alloc<::nsmapped::BasicTypes<_Alloc>>>
    {};
}


