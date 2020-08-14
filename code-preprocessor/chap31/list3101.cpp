/** @file list3101.cpp */
/** Listing 31-1. Overloading the Equality Operator */
#include <cassert>
#include <iostream>
#include <numeric>

/// Represents a rational number.
struct rational
{
  /// Constructs a rational object, given a numerator and a denominator.
  /// Always reduces to normal form.
  /// @param num numerator
  /// @param den denominator
  /// @pre denominator > 0
  rational(int num, int den)
  : numerator{num}, denominator{den}
  {
    reduce();
  }

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
    if (denominator < 0)
    {
      denominator = -denominator;
      numerator = -numerator;
    }
    int div{std::gcd(numerator, denominator)};
    numerator = numerator / div;
    denominator = denominator / div;
  }

  int numerator;     ///< numerator gets the sign of the rational value
  int denominator;   ///< denominator is always positive
};

/// Compares two rational numbers for equality.
/// @pre @p a and @p b are reduced to normal form
bool operator==(rational const& a, rational const& b)
{
  return a.numerator == b.numerator and a.denominator == b.denominator;
}

/// Compare two rational numbers for inequality.
/// @pre @p a and @p b are reduced to normal form
bool operator!=(rational const& a, rational const& b)
{
  return not (a == b);
}

int main()
{
  rational pi1{355, 113};
  rational pi2{1420, 452};

  if (pi1 == pi2)
    std::cout << "success\n";
  else
    std::cout << "failure\n";
}
