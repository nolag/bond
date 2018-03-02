#pragma once

#include <cstdlib>

namespace helloworld_with_template_alloc
{
    template <typename T>
    struct ExampleAllocator
    {
        using value_type = T;

        ExampleAllocator() = default;

        template <typename U>
        ExampleAllocator(const ExampleAllocator<U>& /*other*/)
        {}

        T* allocate(std::size_t n)
        {
            return static_cast<T*>(std::malloc(n * sizeof(T)));
        }

        void deallocate(T* p, std::size_t)
        {
            std::free(p);
        }
    };

    template <typename T>
    inline bool operator==(const ExampleAllocator<T>& /*first*/, const ExampleAllocator<T>& /*second*/)
    {
        return true;
    }

    template <typename T>
    inline bool operator!=(const ExampleAllocator<T>& /*first*/, const ExampleAllocator<T>& /*second*/)
    {
        return false;
    }

}