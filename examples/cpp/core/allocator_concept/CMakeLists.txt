add_bond_codegen (custom_allocator.bond
    OPTIONS 
        --allocator_concept
        --allocator=\"examples::custom_allocator::MyAllocator<char>\"
        --header=\\\"allocator.h\\\"
        --alloc-ctors)

add_bond_test (allocator_concept
	${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/allocator_concept_types.cpp
	allocator_concept.cpp)
