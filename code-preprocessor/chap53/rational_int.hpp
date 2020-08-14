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

class rational
{
public:
  using value_type = int;
  constexpr rational() : rational{0} {}
  constexpr rational(value_type num) : numerator_{num}, denominator_{1} {}
  rational(value_type num, value_type den);

  void assign(value_type num, value_type den);

  rational const& operator +=(rational const& rhs);
  rational const& operator -=(rational const& rhs);
  rational const& operator *=(rational const& rhs);
  rational const& operator /=(rational const& rhs);

  template<class U>
  U convert()
  const
  {
    return static_cast<U>(numerator()) / static_cast<U>(denominator());
  }

  constexpr value_type const& numerator() const { return numerator_; }
  constexpr value_type const& denominator() const { return denominator_; }
private:
  void reduce();
  value_type numerator_;
  value_type denominator_;
};

rational::rational(value_type num, value_type den)
: numerator_{num}, denominator_{den}
{
  reduce();
}

void rational::assign(value_type num, value_type den)
{
  numerator_ = num;
  denominator_ = den;
  reduce();
}

bool operator==(rational const& a, rational const& b)
{
  return a.numerator() == b.numerator() and
         a.denominator() == b.denominator();
}

inline bool operator!=(rational const& a, rational const& b)
{
  return not (a == b);
}

std::ostream& operator<<(std::ostream& stream, rational const& r)
{
  std::cout << r.numerator() << '/' << r.denominator();
  return stream;
}

std::istream& operator>>(std::istream& in, rational& rat)
{
  int n{}, d{};
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

  void rational::reduce()
  {
    if (denominator() == value_type{}) throw zero_denominator("divide by zero in rational");
    if (denominator() < value_type{})
    {
      denominator_ = -denominator();
      numerator_ = -numerator();
    }
    int div{std::gcd(numerator(), denominator())};
    numerator_ = numerator() / div;
    denominator_ = denominator() / div;
  }

rational operator-(rational const& r)
{
  return rational{-r.numerator(), r.denominator()};
}

#endif
