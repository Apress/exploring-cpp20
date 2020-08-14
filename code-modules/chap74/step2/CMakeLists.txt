add_executable(calc2 calc.cpp parse.cpp variables.cpp)

add_executable(test_main2 test_main.cpp test_parse.cpp parse.cpp variables.cpp)
target_link_libraries(test_main2 gtest)

add_test(NAME test_chap74_step2 COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_main2)
