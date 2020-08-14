/** @file list3108.cpp */
/** Listing 31-8. Test Program for Multiplying an Integer and a Rational Number */
#include <cassert>
#include <iostream>
#include <numeric>

// ... struct rational omitted for brevity ...

#include "list3108.inc0"

int main()
{
  rational result{3 * rational{1, 3}};
  std::cout << result.numerator << '/' << result.denominator << '\n';
}
