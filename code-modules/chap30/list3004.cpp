/** @file list3004.cpp */
/** Listing 30-4. Adding the assign Member Function */
#include <cassert>
import <iostream>;
import <numeric>;

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
  pi.assign(1420, 452);
  std::cout << "pi is approximately " << pi.numerator << "/" << pi.denominator << '\n';
}
