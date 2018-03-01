#include "precompiled.h"

#include "allocator_concept_default_allocator_tests_generated/allocator_test_reflection.h"
#include "allocator_concept_custom_allocator_tests_generated/allocator_test_reflection.h"

#include <boost/mpl/list.hpp>
#include <boost/range/combine.hpp>
#include <boost/range/irange.hpp>
#include <boost/test/unit_test.hpp>

#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 4100)
#endif

#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>

#ifdef _MSC_VER
#pragma warning (pop)
#endif

#include <memory>
#include <type_traits>
#include <vector>

template<template <template <typename> typename> typename T, typename Reader, template <typename> typename DefaultAlloc, template <typename> typename OtherAlloc>
void AllocatorConceptTestHelper()
{
    DefaultAlloc<T<DefaultAlloc> > defaultAlloc;
    OtherAlloc<T<OtherAlloc> > otherAlloc;

    boost::shared_ptr<T<DefaultAlloc> > from = boost::allocate_shared<T<DefaultAlloc> >(defaultAlloc, defaultAlloc);
    InitRandom(*from);

    // Serialize
    typename bond::get_protocol_writer<Reader, bond::OutputBuffer>::type::Buffer output;
    typename bond::get_protocol_writer<Reader, bond::OutputBuffer>::type writer(output);
    bond::Serialize(*from, writer);

    bond::blob data = output.GetBuffer();

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

        BOOST_CHECK(*x == *y);

        typename bond::get_protocol_writer<Reader, bond::OutputBuffer>::type::Buffer output2;
        typename bond::get_protocol_writer<Reader, bond::OutputBuffer>::type writer2(output2);
        bond::Serialize(*y, writer2);
        bond::blob data2 = output2.GetBuffer();

        Reader reader2(data2);
        bond::Deserialize(reader2, *toSameAlloc);

        BOOST_CHECK(*from == *toSameAlloc);
    }

    // Runtime-time deserialize
    {
        boost::shared_ptr<T<OtherAlloc> > toOtherAllocator = boost::allocate_shared<T<OtherAlloc> >(otherAlloc, otherAlloc);
        boost::shared_ptr<T<DefaultAlloc> > toSameAlloc = boost::allocate_shared<T<DefaultAlloc> >(defaultAlloc, defaultAlloc);

        Reader reader2(data);
        bond::bonded<void> bonded(reader2, bond::GetRuntimeSchema<T<OtherAlloc> >());

        bonded.Deserialize(*toOtherAllocator);

        typename bond::get_protocol_writer<Reader, bond::OutputBuffer>::type::Buffer output2;
        typename bond::get_protocol_writer<Reader, bond::OutputBuffer>::type writer2(output2);
        bond::Serialize(*toOtherAllocator, writer2);
        bond::blob data2 = output2.GetBuffer();

        Reader reader(data2);
        bond::bonded<void> bonded2(reader2, bond::GetRuntimeSchema<T<DefaultAlloc>>());

        bonded2.Deserialize(*toSameAlloc);

        BOOST_CHECK(*from == *toSameAlloc);
    }
}

BOOST_AUTO_TEST_SUITE(AllocatorConceptTests)

using all_protocols = boost::mpl::list<
    bond::SimpleBinaryReader<bond::InputBuffer>,
    bond::CompactBinaryReader<bond::InputBuffer>,
    bond::FastBinaryReader<bond::InputBuffer> >;

BOOST_AUTO_TEST_CASE_TEMPLATE(BondAllocatorConceptNoDefaultTypeProvidedDeserializationTest, Reader, all_protocols)
{
    AllocatorConceptTestHelper<allocator_concept_default_allocator_tests::Struct, Reader, std::allocator, detail::TestAllocator>();
}

BOOST_AUTO_TEST_CASE_TEMPLATE(BondAllocatorConceptDefaultTypeProvidedDeserializationTest, Reader, all_protocols)
{
    AllocatorConceptTestHelper<allocator_concept_custom_allocator_tests::Struct, Reader, detail::TestAllocator, std::allocator>();
}

// This test compiling proves that the defaults of the type are correct.
// Since templated arguments cannot use defaults, we don't use templates here
BOOST_AUTO_TEST_CASE(AllocatorConceptUsesCorrectDefaultAllocatorTest)
{
    allocator_concept_default_allocator_tests::Struct<> stdAlloc;
    allocator_concept_custom_allocator_tests::Struct<> customAlloc;
    allocator_concept_default_allocator_tests::Struct<std::allocator> stdAlloc2;
    stdAlloc = stdAlloc2;
    allocator_concept_custom_allocator_tests::Struct<detail::TestAllocator> customAlloc2;
    customAlloc = customAlloc2;
}

BOOST_AUTO_TEST_SUITE_END()

    bool init_unit_test()
{
    return true;
}
