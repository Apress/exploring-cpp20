#include <iostream>
#include <numeric>
#include <stdexcept>
#include "list5407.hh"

int main()
{
    constexpr int x1{ ipower(0, 10) };
    constexpr int x2{ ipower(10, 0) };
    constexpr int x3{ ipower(10, 3) };
    constexpr int x4{ ipower(2, 3) };
    constexpr int x5{ ipower(3, 4) };

    std::cout << x1 << '\n' << x2 << '\n' << x3 << '\n' << x4 << '\n' << x5 << '\n';
}
