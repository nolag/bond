add_bond_test (grpc-helloworld-with-allocator-concept helloworld_with_allocator_concept.bond helloworld_with_allocator_concept.cpp GRPC ALLOCATOR_CONCEPT)

cxx_target_compile_definitions (MSVC grpc-helloworld-with-allocator-concept  PRIVATE -D_WIN32_WINNT=0x0600)

target_link_libraries(grpc-helloworld-with-allocator-concept PRIVATE grpc++)