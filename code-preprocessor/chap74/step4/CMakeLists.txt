set(source_files calc_error.cpp node.cpp node_impl.cpp parse.cpp variables.cpp)
add_executable(calc4 calc.cpp ${source_files})

add_executable(test_main4 test_main.cpp test_node.cpp node_impl.cpp test_parse.cpp ${source_files})
target_link_libraries(test_main4 gtest)

add_test(NAME test_chap74_step4 COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_main4)
