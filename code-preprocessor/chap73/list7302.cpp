/** @file list7302.cpp */
/** Listing 73-2. Adding constexpr Throughout the rational Class Template */
#include <iostream>
#include "rational.hpp"

constinit rational<long> r{355, 113};
constinit rational<long> const q{31416, 10000};

int main()
{
    constexpr rational<long> p{2};
    r /= q;
    r *= p;
    std::cout << r << '\n';
}
