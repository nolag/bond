add_bond_codegen (scoped_allocator_with_template_alloc.bond
    OPTIONS 
        --allocator=\"examples::scoped_allocator_with_template_alloc::MyAllocator\"
        --header=\\\"allocator.h\\\"
        --alloc-ctors
        --template-alloc
        --scoped-alloc)

add_bond_test (scoped_allocator_with_template_alloc
	${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/scoped_allocator_with_template_alloc_types.cpp
	scoped_allocator_with_template_alloc.cpp)
