set(source_files calc_error.cpp node.cpp node_impl.cpp number.cpp number_impl.cpp parse.cpp variables.cpp)
add_executable(calc6 calc.cpp ${source_files})

add_executable(test_main6 test_main.cpp test_node.cpp node_impl.cpp test_parse.cpp ${source_files})
target_link_libraries(test_main6 gtest)

add_test(NAME test_chap74_step6 COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_main6)
