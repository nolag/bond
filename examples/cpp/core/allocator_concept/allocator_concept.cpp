#include "allocator_concept_reflection.h"

#include <bond/core/bond.h>
#include <bond/stream/output_buffer.h>
#include <cassert>
#include <memory>

using namespace examples::allocator_concept;


int main()
{
    MyAllocator<char> alloc{ 123 };

    Struct<MyAllocator> obj{ alloc };
    obj.ints.push_back(1);
    obj.strings.strings.emplace_back("test");           // Allocator is automatically propagated.
    obj.strings_vector.emplace_back();                  // Allocator is automatically propagated.
    obj.strings_vector[0].strings.emplace_back("test2");// Allocator is automatically propagated.

    bond::OutputBuffer output1;
    bond::CompactBinaryWriter<bond::OutputBuffer> writer1{ output1 };

    Serialize(obj, writer1);

    bond::CompactBinaryReader<bond::InputBuffer> reader1{ output1.GetBuffer() };

    Struct<std::allocator> obj2;
    Deserialize(reader1, obj2);
    
    bond::OutputBuffer output2;
    bond::CompactBinaryWriter<bond::OutputBuffer> writer2{ output2 };

    Serialize(obj2, writer2);

    bond::CompactBinaryReader<bond::InputBuffer> reader2{ output2.GetBuffer() };
    
    // Types cannot be compared directly because the allocators are different, but items must be the same.  The easiest way to test this is to serialize and deserialize again
    
    Struct<MyAllocator> obj3{ alloc };
    Deserialize(reader2, obj3);

    assert(obj == obj3);
    
    return 0;
}
