add_bond_codegen (helloworld_with_allocator_concept.bond
    OPTIONS 
        --allocator-concept
        --grpc)

add_bond_test (grpc-helloworld-with-allocator-concept 
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/helloworld_with_allocator_concept_types.cpp
    helloworld_with_allocator_concept.cpp GRPC)        
        
cxx_target_compile_definitions (MSVC grpc-helloworld-with-allocator-concept  PRIVATE -D_WIN32_WINNT=0x0600)

target_link_libraries(grpc-helloworld-with-allocator-concept PRIVATE grpc++)