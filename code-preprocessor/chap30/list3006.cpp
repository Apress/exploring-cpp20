// Copied from list3004.cpp, changing reduce() to #include
// and numerator and denominator to negative numbers.

#include <cassert>
#include <iostream>
#include <numeric>

/// Represents a rational number.
struct rational
{
  /// Assigns a numerator and a denominator, then reduces to normal form.
  /// @param num numerator
  /// @param den denominator
  /// @pre denominator > 0
  void assign(int num, int den)
  {
    numerator = num;
    denominator = den;
    reduce();
  }

  /// Reduces the numerator and denominator by their GCD.
#include "list3006.hh"

  int numerator;     ///< numerator gets the sign of the rational value
  int denominator;   ///< denominator is always positive
};

int main()
{
  rational pi{};
  pi.assign(-1420, -452);
  std::cout << "pi is approximately " << pi.numerator << "/" << pi.denominator << '\n';
}
