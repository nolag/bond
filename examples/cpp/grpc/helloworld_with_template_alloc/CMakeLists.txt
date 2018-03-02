add_bond_codegen (helloworld_with_template_alloc.bond
    OPTIONS 
        --template-alloc
        --grpc)

add_bond_test (grpc-helloworld-with-template-alloc 
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/helloworld_with_template_alloc_types.cpp
    helloworld_with_template_alloc.cpp GRPC)        
        
cxx_target_compile_definitions (MSVC grpc-helloworld-with-template-alloc  PRIVATE -D_WIN32_WINNT=0x0600)

target_link_libraries(grpc-helloworld-with-template-alloc PRIVATE grpc++)