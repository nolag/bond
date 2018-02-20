add_bond_codegen (allocator_concept.bond
    OPTIONS 
        --allocator-concept
        --allocator=\"examples::allocator_concept::MyAllocator\"
        --header=\\\"allocator.h\\\"
        --alloc-ctors)

add_bond_test (allocator_concept
	${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/allocator_concept_types.cpp
	allocator_concept.cpp)
