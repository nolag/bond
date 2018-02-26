#pragma once

#include <type_traits>

namespace helloworld_with_allocator_concept
{

template<typename T>
class ExampleAllocator
{
public:
    typedef typename std::remove_const<T>::type value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef const value_type* const_pointer;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    ExampleAllocator()
    {}

    template<typename U>
    ExampleAllocator(const ExampleAllocator<U>&)
    {}

    template<class Other>
    struct rebind
    {
        // convert this type to ExampleAllocator<Other>
        typedef ExampleAllocator<Other> other;
    };

    bool operator==(const ExampleAllocator&) const
    {
        return true;
    }

    bool operator!=(const ExampleAllocator&) const
    {
        return false;
    }

    pointer address(reference val) const
    {
        return &val;
    }

    const_pointer address(const_reference val) const
    {
        return &val;
    }

    void deallocate(pointer ptr, size_type)
    {
        free(ptr);
    }

    pointer allocate(size_type count)
    {
        if (count < 0xffffffff)
            return static_cast<T*>(malloc(sizeof(T)* count));
        else
            throw std::bad_alloc();
    }

    pointer allocate(size_type count, const void*)
    {
        // allocate array of count elements, ignore hint
        return allocate(count);
    }

    void construct(pointer ptr, const T& val)
    {
        // construct object at ptr with value val
        new((void*)ptr) T(val);
    }

#if !defined(BOND_NO_CXX11_ALLOCATOR)
    template <typename U, typename ...Args>
    void construct(U* ptr, Args&&...args)
    {
        new ((void*)ptr) (U)(std::forward<Args>(args)...);
    }
#endif

    void destroy(pointer ptr)
    {
        (void)ptr;
        // destroy object at ptr
        ptr->~T();
    }

    size_type max_size() const
    {
        // estimate maximum array size
        size_type count = static_cast<size_type>(-1) / sizeof(T);
        return count > 0 ? count : 1;
    }
};

}