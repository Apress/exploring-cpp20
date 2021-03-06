#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <iostream>
#include <numeric>
#include <stdexcept>

class zero_denominator : public std::logic_error
{
public:
    using logic_error::logic_error;
};

#include "list5203.hh"

template<class T>
std::ostream& operator<<(std::ostream& stream, rational<T> const& r)
{
  std::cout << r.numerator() << '/' << r.denominator();
  return stream;
}

template<class T>
std::istream& operator>>(std::istream& in, rational<T>& rat)
{
  T n{}, d{};
  char sep{};
  if (not (in >> n >> sep))
    // Error reading the numerator or the separator character.
    in.setstate(in.failbit);
  else if (sep != '/')
  {
    // Push sep back into the input stream, so the next input operation
    // will read it.
    in.unget();
    rat.assign(n, 1);
  }
  else if (in >> d)
    // Successfully read numerator, separator, and denominator.
    rat.assign(n, d);
  else
    // Error reading denominator.
    in.setstate(in.failbit);

  return in;
}

template<class T>
  void rational<T>::reduce()
  {
    if (denominator() == value_type{}) throw zero_denominator("divide by zero in rational");
    if (denominator() < value_type{})
    {
      denominator_ = -denominator();
      numerator_ = -numerator();
    }
    T div{std::gcd(numerator(), denominator())};
    numerator_ = numerator() / div;
    denominator_ = denominator() / div;
  }


#endif
