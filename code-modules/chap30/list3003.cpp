/** @file list3003.cpp */
/** Listing 30-3. Adding the reduce Member Function */
#include <cassert>

import <iostream>;
import <numeric>;

/// Represents a rational number.
struct rational
{
  /// Reduce the numerator and denominator by their GCD.
  void reduce()
  {
    assert(denominator != 0);
    int div{std::gcd(numerator, denominator)};
    numerator = numerator / div;
    denominator = denominator / div;
  }
  int numerator;     ///< numerator gets the sign of the rational value
  int denominator;   ///< denominator is always positive
};

int main()
{
  rational pi{};
  pi.numerator = 1420;
  pi.denominator = 452;
  pi.reduce();
  std::cout << "pi is approximately " << pi.numerator << "/" << pi.denominator << '\n';
}
