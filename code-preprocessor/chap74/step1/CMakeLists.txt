add_executable(calc1 calc.cpp parse.cpp)

add_executable(test_main1 test_main.cpp test_parse.cpp parse.cpp)
target_link_libraries(test_main1 gtest)

add_test(NAME test_chap74_step1 COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_main1)
