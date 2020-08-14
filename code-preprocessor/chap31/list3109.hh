/** @file list3109.hh */
/** Listing 31-9. Constructing a Rational Number from a Floating-Point Argument */
struct rational
{
  rational(int num, int den)
  : numerator{num}, denominator{den}
  {
    reduce();
  }

  rational(double r)
  : rational{static_cast<int>(r * 100000), 100000}
  {}

//   ... omitted for brevity ...

#include "list3109.inc0"

  int numerator;
  int denominator;
};
