add_bond_codegen (scoped_allocator_with_allocator_concept.bond
    OPTIONS 
        --allocator=\"examples::scoped_allocator_with_allocator_concept::MyAllocator\"
        --header=\\\"allocator.h\\\"
        --alloc-ctors
        --allocator-concept
        --scoped-alloc)

add_bond_test (scoped_allocator_with_allocator_concept
	${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/scoped_allocator_with_allocator_concept_types.cpp
	scoped_allocator_with_allocator_concept.cpp)
