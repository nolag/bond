#include "precompiled.h"

#include <memory>

#include "allocators.h"
#include "allocator_concept_default_allocator_tests_generated/allocator_test_reflection.h"
#include "allocator_concept_custom_allocator_tests_generated/allocator_test_reflection.h"
#include "serialization_test.h"

template<template <template <typename> typename> typename T, typename Reader, template <typename> typename Writer, template <typename> typename DefaultAlloc, template <typename> typename OtherAlloc>
TEST_CASE_BEGIN(AllocatorConceptTest)     
{
    typedef bond::OutputMemoryStream<DefaultAlloc<T<DefaultAlloc> > > DefaultAllocatorOutputStream;
    typedef bond::OutputMemoryStream<OtherAlloc<T<OtherAlloc> > > OtherAllocatorOutputStream;
    
    DefaultAlloc<T<DefaultAlloc> > defaultAlloc;
    OtherAlloc<T<OtherAlloc> > otherAlloc;
    
    boost::shared_ptr<T<DefaultAlloc> > from = boost::allocate_shared<T<DefaultAlloc> >(defaultAlloc, defaultAlloc);
    InitRandom(*from);

    // Serialize
    typename Writer<DefaultAllocatorOutputStream>::Buffer buffer(defaultAlloc);
    Writer<DefaultAllocatorOutputStream> writer(buffer);
    bond::Serialize(*from, writer);
        
    bond::blob data = buffer.GetBuffer();

    // Compile-time deserialize, serialize to other type then go back to assure it works.
    {
        boost::shared_ptr<T<OtherAlloc> > toOtherAllocator = boost::allocate_shared<T<OtherAlloc> >(otherAlloc, otherAlloc);
        boost::shared_ptr<T<DefaultAlloc> > toSameAlloc = boost::allocate_shared<T<DefaultAlloc> >(defaultAlloc, defaultAlloc);

        Reader reader(data);
        bond::Deserialize(reader, *toOtherAllocator);
        
        boost::shared_ptr<T<OtherAlloc> > x = boost::allocate_shared<T<OtherAlloc> >(otherAlloc, otherAlloc);
        boost::shared_ptr<T<OtherAlloc> > y = boost::allocate_shared<T<OtherAlloc> >(otherAlloc, otherAlloc);
        
        *x = *toOtherAllocator;
        y->swap(*toOtherAllocator);

        UT_Compare(*x, *y);
        
        
        typename Writer<OtherAllocatorOutputStream>::Buffer buffer2(otherAlloc);
        Writer<OtherAllocatorOutputStream> writer2(buffer2);
        bond::Serialize(*y, writer2);
        bond::blob data2 = buffer2.GetBuffer();
        
        Reader reader2(data2);
        bond::Deserialize(reader2, *toSameAlloc);
        
        UT_Compare(*from, *toSameAlloc);
    }

    // Runtime-time deserialize
    {
        boost::shared_ptr<T<OtherAlloc> > toOtherAllocator = boost::allocate_shared<T<OtherAlloc> >(otherAlloc, otherAlloc);
        boost::shared_ptr<T<DefaultAlloc> > toSameAlloc = boost::allocate_shared<T<DefaultAlloc> >(defaultAlloc, defaultAlloc);

        Reader reader2(data);
        bond::bonded<void> bonded(reader2, bond::GetRuntimeSchema<T<OtherAlloc> >());
        
        bonded.Deserialize(*toOtherAllocator);
        
        typename Writer<OtherAllocatorOutputStream>::Buffer buffer2(otherAlloc);
        Writer<OtherAllocatorOutputStream> writer2(buffer2);
        bond::Serialize(*toOtherAllocator, writer2);
        bond::blob data2 = buffer2.GetBuffer();
        
        Reader reader(data2);
        bond::bonded<void> bonded2(reader2, bond::GetRuntimeSchema<T<DefaultAlloc> >());

        bonded2.Deserialize(*toSameAlloc);

        UT_Compare(*from, *toSameAlloc);
    }
}
TEST_CASE_END

// This test compiling proves that the defaults of the type are correct.
// Since templated arguments cannot use defaults, we don't use templates here
TEST_CASE_BEGIN(AllocatorDefaultTest)
{
    allocator_concept_default_allocator_tests_generated::Struct<> stdAlloc;
    allocator_concept_custom_allocator_tests_generated::Struct<> customAlloc;
    allocator_concept_default_allocator_tests_generated::Struct<std::allocator> stdAlloc2;
    stdAlloc = stdAlloc2;
    allocator_concept_custom_allocator_tests_generated::Struct<detail::TestAllocator> customAlloc2;
    customAlloc = customAlloc2;
}
TEST_CASE_END

template <uint16_t N, typename Reader, template <typename> typename Writer>
void AllocatorConceptTests(const char* name)
{
    UnitTestSuite suite(name);

    AddTestCase<TEST_ID(N), 
        AllocatorConceptTest, allocator_concept_default_allocator_tests_generated::Struct, Reader, Writer, std::allocator, detail::TestAllocator>(suite, "allocator_concept_default_allocator_tests_generated::Struct");

    AddTestCase<TEST_ID((N + 1)),
        AllocatorConceptTest, allocator_concept_custom_allocator_tests_generated::Struct, Reader, Writer, detail::TestAllocator, std::allocator>(suite, "allocator_concept_custom_allocator_tests_generated::Struct");
}

void AllocatorConceptTestsInit()
{
    TEST_SIMPLE_PROTOCOL(
        AllocatorConceptTests<
            0x1901,
            bond::SimpleBinaryReader<bond::InputBuffer>,
            bond::SimpleBinaryWriter>("Allocator concept tests for SimpleBinary");
    );

    TEST_COMPACT_BINARY_PROTOCOL(
        AllocatorConceptTests<
            0x1903,
            bond::CompactBinaryReader<bond::InputBuffer>,
            bond::CompactBinaryWriter>("Allocator concept tests for CompactBinary");
    );

    TEST_FAST_BINARY_PROTOCOL(
        AllocatorConceptTests<
            0x1905,
            bond::FastBinaryReader<bond::InputBuffer>,
            bond::FastBinaryWriter>("Allocator concept tests for FastBinary");
    );

    UnitTestSuite suite("Default allocation types");
    AddTestCase<TEST_ID(0x1906), AllocatorDefaultTest>(suite, "Default allocation types");
}

bool init_unit_test()
{
    AllocatorConceptTestsInit();
    return true;
}

