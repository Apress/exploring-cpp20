add_executable(test_currency test.cpp test.hpp currency.hpp fixed.hpp)
add_test(NAME test_chap61 COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_currency)
