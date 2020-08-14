#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>

constexpr void test_function(bool condition, char const* label, char const* filename, long long line_number)
{
    if (not condition)
        std::cerr << "FAIL in " << filename << " on line " << line_number << ' ' << label << '\n';
}

#define STRINGIFY(_x_) #_x_
#define TEST(...) do {                                          \
    auto _condition_{__VA_ARGS__};                              \
    auto _label_{ STRINGIFY((__VA_ARGS__)) };                   \
    test_function(_condition_, _label_, __FILE__, __LINE__);    \
} while(false)

#endif // TEST_HPP_
