add_bond_codegen (template_alloc.bond
    OPTIONS 
        --template-alloc
        --allocator=\"examples::template_alloc::MyAllocator\"
        --header=\\\"allocator.h\\\"
        --alloc-ctors)

add_bond_test (template_alloc
	${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/template_alloc_types.cpp
	template_alloc.cpp)
