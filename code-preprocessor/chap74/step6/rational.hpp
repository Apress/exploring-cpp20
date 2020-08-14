#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <format>
#include <istream>
#include <limits>
#include <numeric>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>

#include "ioflags.hpp"
#include "ipower.hpp"

/// Exception class if the denominator is ever zero.
class zero_denominator : public std::logic_error
{
public:
  /// Construct the exception object.
  zero_denominator(std::string const& what) : logic_error{what} {}
};

/// Represent a rational number (fraction) as a numerator and denominator.
template<class T>
requires std::integral<T>
class rational
{
public:
  /// Convenience typedef for the integral type of the numerator and denominator.
  using value_type = T;

  /// Default constructor and constructor from a single value.
  /// As a default constructor, initializes to zero.
  /// Otherwise, initializes to the integer @p num.
  /// @param num The integer value to use as the initial value
  constexpr rational(value_type num = 0): numerator_{num}, denominator_{1} {}
  /// Construct a rational number
  /// @param num numerator
  /// @param den denominator
  /// @throws zero_denominator if @p den == 0
  rational(value_type num, value_type den);
  /// Initialize the rational number with an approximation of @p r
  /// @param r the initial value
  rational(double r);
  /// Copy from a different type of rational.
  template<class U>
  rational(rational<U> const& that);

  /// Return the numerator
  constexpr value_type numerator()              const { return numerator_; }
  /// Return the denominator
  constexpr value_type denominator()            const { return denominator_; }
  /// Convert the rational number to a floating-point type
  template<class U>
  requires std::floating_point<U>
  constexpr explicit operator U() const { return static_cast<U>(numerator()) / static_cast<U>(denominator()); }

  /// Assignment of an integer
  template<class Int>
  requires std::integral<Int>
  constexpr rational& operator=(Int value) {
	  numerator_ = value;
	  denominator_ = value_type{1};
	  return *this;
  }

  /// Assignment of a rational with a different size.
  template<class U>
  rational& operator=(rational<U> const& rhs);

  /// Addition assignment operator
  rational& operator+=(rational const& rhs);
  /// Addition assignment operator
  rational& operator+=(value_type const& rhs);

  /// Subtraction assignment operator
  rational& operator-=(rational const& rhs);
  /// Subtraction assignment operator
  rational& operator-=(value_type const& rhs);

  /// Multiplication assignment operator
  rational& operator*=(rational const& rhs);
  /// Multiplication assignment operator
  rational& operator*=(value_type const& rhs);

  /// Division assignment operator
  rational& operator/=(rational const& rhs);
  /// Division assignment operator
  rational& operator/=(value_type const& rhs);

  /// Pre-increment
  rational& operator++();
  /// Pre-decrement
  rational& operator--();
  /// Post-increment
  rational operator++(int);
  /// Post-decrement
  rational operator--(int);

private:
  /// Reduce the numerator and denominator by their GCD.
  void reduce();
  /// Reduce the numerator and denominator, and normalize the signs of both,
  /// that is, ensure denominator is not negative.
  void normalize();
  /// Scale an integer of type @p U to the value_type. If @p U has more
  /// digits than @p value_type shift @p value to the right.
  template<class U>
  value_type scale(U value);

  /// Compute the divisor to use when converting a @c double to @c rational.
  /// This is the largest power of 10 that @c value_type can represent.
  static constexpr value_type double_divisor = ipower<value_type>(value_type{10}, std::numeric_limits<value_type>::digits10 - 1);

  value_type numerator_;
  value_type denominator_;
};

template<class T>
rational<T>::rational(value_type num, value_type den)
: numerator_{num},
  denominator_{den == value_type{} ? throw zero_denominator{"zero denominator"} : den}
{
  normalize();
}

template<class T>
rational<T>::rational(double r)
: numerator_{static_cast<T>(r / double_divisor + 0.5)}, denominator_{double_divisor}
{}

template<class T>
template<class U>
rational<T>::rational(rational<U> const& that)
: numerator_{scale<U>(that.numerator())}, denominator_{scale<U>(that.denominator())}
{
  reduce();
}

template<class T>
template<class U>
T rational<T>::scale(U value)
{
  if (std::numeric_limits<T>::digits >= std::numeric_limits<U>::digits)
    return T{value};
  else
    return T{value >> (std::numeric_limits<U>::digits - std::numeric_limits<T>::digits)};
}

template<class T>
void rational<T>::normalize()
{
  if (denominator_ < value_type{})
  {
    denominator_ = -denominator_;
    numerator_ = -numerator_;
  }
  reduce();
}

template<class T>
void rational<T>::reduce()
{
  value_type div{std::gcd(numerator(), denominator())};
  if (div == value_type{})
    throw zero_denominator{"zero denominator"};
  numerator_ /= div;
  denominator_ /= div;
}

template<class T>
template<class U>
rational<T>& rational<T>::operator=(rational<U> const& rhs)
{
  numerator_ = scale<U>(rhs.numerator());
  denominator_ = scale<U>(rhs.denominator());
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator+=(rational const& rhs)
{
  numerator_ = numerator() * rhs.denominator() + rhs.numerator() * denominator();
  denominator_ *= rhs.denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator+=(value_type const& rhs)
{
  numerator_ = numerator() + rhs * denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator-=(rational const& rhs)
{
  numerator_ = numerator() * rhs.denominator() - rhs.numerator() * denominator();
  denominator_ *= rhs.denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator-=(value_type const& rhs)
{
  numerator_ = numerator() - rhs * denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator*=(rational const& rhs)
{
  numerator_ *= rhs.numerator();
  denominator_ *= rhs.denominator();
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator*=(value_type const& rhs)
{
  numerator_ *= rhs;
  reduce();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator/=(rational const& rhs)
{
  if (rhs.numerator() == value_type{})
    throw zero_denominator{"divide by zero"};
  numerator_ *= rhs.denominator();
  denominator_ *= rhs.numerator();
  normalize();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator/=(value_type const& rhs)
{
  if (rhs == value_type{})
    throw zero_denominator{"divide by zero"};
  denominator_ *= rhs;
  normalize();
  return *this;
}

template<class T>
rational<T>& rational<T>::operator++()
{
  numerator_ += denominator();
  return *this;
}

template<class T>
rational<T> rational<T>::operator++(int)
{
  rational result(*this);
  ++*this;
  return result;
}

template<class T>
rational<T>& rational<T>::operator--()
{
  numerator_ -= denominator();
  return *this;
}

template<class T>
rational<T> rational<T>::operator--(int)
{
  rational result(*this);
  --*this;
  return result;
}

/// Negate a rational number
template<class T>
rational<T> operator-(rational<T> const& r)
{
  return rational<T>{-r.numerator(), r.denominator()};
}

template<class T>
rational<T> absval(rational<T> const& r)
{
  using std::abs;
  return rational<T>{abs(r.numerator()), r.denominator()};
}

/// Addition
template<class T>
rational<T> operator+(rational<T> lhs, rational<T> const& rhs)
{
  lhs += rhs;
  return lhs;
}

/// Addition
template<class T>
rational<T> operator+(rational<T> lhs, T const& rhs)
{
  lhs += rhs;
  return lhs;
}

/// Addition
template<class T>
rational<T> operator+(T const& lhs, rational<T> rhs)
{
  rhs += lhs;
  return rhs;
}

/// Subtraction
template<class T>
rational<T> operator-(rational<T> lhs, rational<T> const& rhs)
{
  lhs -= rhs;
  return lhs;
}

/// Subtraction
template<class T>
rational<T> operator-(rational<T> lhs, T const& rhs)
{
  lhs -= rhs;
  return lhs;
}

/// Subtraction
template<class T>
rational<T> operator-(T const& lhs, rational<T> rhs)
{
  // Gotta be a little tricky.
  rhs += -lhs;
  return -rhs;
}

/// Multiplication
template<class T>
rational<T> operator*(rational<T> lhs, rational<T> const& rhs)
{
  lhs *= rhs;
  return lhs;
}

/// Multiplication
template<class T>
rational<T> operator*(rational<T> lhs, T const& rhs)
{
  lhs *= rhs;
  return lhs;
}

/// Multiplication
template<class T>
    rational<T> operator*(T const& lhs, rational<T> rhs)
{
  rhs *= lhs;
  return rhs;
}

/// Division
template<class T>
rational<T> operator/(rational<T> lhs, rational<T> const& rhs)
{
  lhs /= rhs;
  return lhs;
}

/// Division
template<class T>
rational<T> operator/(rational<T> lhs, T const& rhs)
{
  lhs /= rhs;
  return lhs;
}

/// Division
template<class T>
rational<T> operator/(T const& lhs, rational<T> rhs)
{
  return rational<T>{lhs * rhs.denominator(), rhs.numerator()};
}


/// Equality comparison
template<class T, class U>
constexpr bool operator==(rational<T> const& a, rational<U> const& b)
{
  return a.numerator() * b.denominator() == b.numerator() * a.denominator();
}

/// Equality comparison
template<class T>
constexpr bool operator==(rational<T> const& a, rational<T> const& b)
{
  return (a.denominator() == b.denominator()) and
    a.numerator() == b.numerator();
}

/// Equality comparison
template<class T>
constexpr bool operator==(rational<T> const& lhs, T rhs)
{
  return lhs.denominator() == 1 and
         lhs.numerator()   == rhs;
}

/// Equality comparison
template<class T>
constexpr bool operator==(T lhs, rational<T> const& rhs)
{
  return rhs.denominator() == 1 and
         rhs.numerator()   == lhs;
}

/// Less-than comparison
template<class T>
constexpr bool operator<(rational<T> const& a, rational<T> const& b)
{
  return a.numerator() * b.denominator() < b.numerator() * a.denominator();
}

/// Less-than comparison
template<class T>
constexpr bool operator<(rational<T> const& a, T const& b)
{
  return a.numerator() < b * a.denominator();
}

/// Less-than comparison
template<class T>
constexpr bool operator<(T const& a, rational<T> const& b)
{
  return a * b.denominator() < b.numerator();
}

/// Inequality comparison
template<class T, class U>
constexpr bool operator!=(rational<T> const& a, rational<U> const& b)
{
  return not (a == b);
}

/// Inequality comparison
template<class T>
constexpr bool operator!=(rational<T> const& a, T b)
{
  return not (a == b);
}

/// Inequality comparison
template<class T>
constexpr bool operator!=(T a, rational<T> const& b)
{
  return not (a == b);
}

/// Less-than-or-equal comparison
template<class T>
constexpr bool operator<=(rational<T> const& a, rational<T> const& b)
{
  return not (b < a);
}

/// Less-than-or-equal comparison
template<class T>
constexpr bool operator<=(rational<T> const& a, T const& b)
{
  return not (b < a);
}

/// Less-than-or-equal comparison
template<class T>
constexpr bool operator<=(T const& a, rational<T> const& b)
{
  return not (b < a);
}

/// Greater-than comparison
template<class T>
constexpr bool operator>(rational<T> const& a, rational<T> const& b)
{
  return b < a;
}

/// Greater-than comparison
template<class T>
constexpr bool operator>(rational<T> const& a, T const& b)
{
  return b < a;
}

/// Greater-than comparison
template<class T>
constexpr bool operator>(T const& a, rational<T> const& b)
{
  return b < a;
}

/// Greater-than-or-equal comparison
template<class T>
constexpr bool operator>=(rational<T> const& a, rational<T> const& b)
{
  return not (b > a);
}

/// Greater-than-or-equal comparison
template<class T>
constexpr bool operator>=(rational<T> const& a, T const& b)
{
  return not (b > a);
}

/// Greater-than-or-equal comparison
template<class T>
constexpr bool operator>=(T const& a, rational<T> const& b)
{
  return not (b > a);
}

/// Input operator
template<class T, class Char, class Traits>
std::basic_istream<Char, Traits>& operator>>(std::basic_istream<Char, Traits>& in, rational<T>& rat)
{
  typename std::basic_istream<Char, Traits>::sentry sentry{in, false};
  ioflags flags{in};

  T n{};
  if (not (in >> n))
    // Error reading the numerator.
    return in;

  in >> std::noskipws;
  char sep{};
  if (not (in >> sep))
    // Error reading the separator character.
    return in;
  else if (sep != '/')
  {
    // Push sep back into the input stream, so the next input operation
    // will read it.
    in.unget();
    rat = n;
    return in;
  }
  else
  {
    T d{};
    if (in >> d)
      // Successfully read numerator, separator, and denominator.
      rat = rational<T>{n, d};
  }

  return in;
}

/// Output operator
template<class T, class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& out, rational<T> const& rat)
{
  out << std::format("{}/{}", rat.numerator(), rat.denominator());
  return out;
}

#endif
