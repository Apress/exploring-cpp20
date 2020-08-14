#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <numeric>
#include "list4910.hh"

inline void rational::reduce()
{
  if (denominator_ == 0)
    throw zero_denominator{"denominator is zero"};
  if (denominator_ < 0)
  {
    denominator_ = -denominator_;
    numerator_ = -numerator_;
  }
  int div{std::gcd(numerator_, denominator_)};
  numerator_ = numerator_ / div;
  denominator_ = denominator_ / div;
}

inline std::ostream& operator<<(std::ostream& stream, rational const& r)
{
    std::cout << r.numerator() << '/' << r.denominator();
    return stream;
}

inline bool operator==(rational const& lhs, rational const& rhs)
{
    return lhs.numerator() == rhs.numerator() and lhs.denominator() == rhs.denominator();
}

inline bool operator<(rational const& lhs, rational const& rhs)
{
    if (lhs.denominator() == rhs.denominator())
        return lhs.numerator() < rhs.numerator();
    else
        return lhs.numerator()*rhs.denominator() < lhs.denominator()*rhs.numerator();
}

rational operator-(rational const& r)
{
	return rational{-r.numerator(), r.denominator()};
}

#endif
