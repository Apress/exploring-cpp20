set(source_files node.cpp node_impl.cpp parse.cpp variables.cpp)
add_executable(calc3 calc.cpp ${source_files})

add_executable(test_main3 test_main.cpp test_node.cpp node_impl.cpp test_parse.cpp ${source_files})
target_link_libraries(test_main3 gtest)

add_test(NAME test_chap74_step3 COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_main3)
