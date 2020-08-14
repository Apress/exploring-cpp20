/** @file rational.cpp */
/** Listing 43-2. The rational Implementation In rational.cpp */
#include "rational.hpp"
#include <cassert>
#include <numeric>
#include <ostream>
void rational::assign(int num, int den)
{
  numerator_ = num;
  denominator_ = den;
  reduce();
}
void rational::reduce()
{
  assert(denominator_ != 0);
  if (denominator_ < 0)
  {
    denominator_ = -denominator_;
    numerator_ = -numerator_;
  }
  int div{std::gcd(numerator_, denominator_)};
  numerator_ = numerator_ / div;
  denominator_ = denominator_ / div;
}
rational& rational::operator=(int num)
{
  numerator_ = num;
  denominator_ = 1;
  return *this;
}
std::ostream& operator<<(std::ostream& stream, rational const& r)
{
    return stream << r.numerator() << '/' << r.denominator();
}
