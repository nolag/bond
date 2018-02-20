add_bond_codegen (custom_allocator.bond
    OPTIONS 
        --allocator_concept
        --allocator=\"examples::custom_allocator::MyAllocator<char>\"
        --header=\\\"allocator.h\\\"
        --alloc-ctors)

add_bond_test (custom_allocator
	custom_allocator.cpp)
