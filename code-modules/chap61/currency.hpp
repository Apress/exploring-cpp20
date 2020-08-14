/** @file currency.hpp
 * Implement a currency type.
 */

/** @mainpage Project 3: Currency Type
 * It’s time for another project. You’re going to continue building on the
 * @c fixed type from Project 2 and incorporate what you’ve learned about
 * locales and I/O. Your task this time is to write a @c currency type.
 *
 * The value is stored as a fixed-point value.
 * I/O is formatted using the @c get_money and @c put_money manipulators.
 *
 * Make sure you can add two currency amounts to get a currency value,
 * subtract two currency amounts to get currency,
 * multiply and divide currency by an integer or rational value
 * to get a currency result, and divide two currency values
 * to get a rational result.
 *
 * As with any project, start small and add functionality as you go.
 * For example, start with the basic data representation,
 * then add I/O operators. Add arithmetic operators one at a time.
 * Write each test function before you implement the feature.
*/

#ifndef CURRENCY_HPP_
#define CURRENCY_HPP_

#include <iomanip>
#include <istream>
#include <locale>
#include <ostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "ioflags.hpp"
#include "fixed.hpp"
#include "rational.hpp"

/** Class to represent a currency value in the global locale. */
template<class T=long, int N=2>
class currency
{
public:
  using int_type = T;                    ///< Storage type
  using value_type = fixed<T,N>;         ///< Type of the actual value

  /// Default constructor initializes the value to zero.
  constexpr currency(std::locale locale = std::locale{})
  : value_{}, locale_{locale}
  {}
  /// Initializes the value to @p integer
  /// @param integer The integer initial value; the fractional part is zero.
  constexpr currency(T integer, std::locale locale = std::locale{})
  : value_{integer}, locale_{locale}
  {}
  /// Initializes the value.
  /// The interpretation of the fractional part depends on @p N.
  /// For example, if @p N is 2, a @p fraction of 9 represents 0.09,
  /// buf if @p N is 5, @p fraction of 9 means 0.0009.
  /// @param integer The integer part of the initial value
  /// @param fraction The fractional part of the initial value
  constexpr currency(T integer, T fraction, std::locale locale = std::locale{})
  : value_{integer, fraction}, locale_{locale}
  {}
  /// Initializes from a floating point number.
  /// @param value the initial value
  constexpr currency(double value, std::locale locale = std::locale{})
  : value_{value}, locale_{locale}
  {}

  /// Copies a value that uses a different precision.
  template<class U, int M>
  constexpr currency(currency<U, M> const& rhs)
  : value_{rhs.value()}, locale_{rhs.locale()}
  {}

  /// Assigns a value that uses a different precision.
  template<class U, int M>
  constexpr currency& operator=(currency<U, M> rhs)
  {
    value_ = rhs.value();
    locale_ = rhs.locale();
    return *this;
  }

  /// Convert to a string.
  /// @returns a string representation of the value, e.g., "$123.04"
  std::string to_string() const;
  /// Overwrites this value with the value read from the stream.
  /// The value in the stream must have the correct number of digits.
  /// If the showbase flag is set, the currency symbol must be present.
  /// @param strm Input stream
  template<class Char, class Traits>
  void read(std::basic_istream<Char, Traits>& strm);

  /// Converts the value to a different numeric type.
  /// Typically, the other type is a floating-point type.
  template<class U>
  /// Converts to some other type, especially floating point.
  constexpr U convert() const { return value().template convert<U>(); }

  /// Rounds off to the nearest integer, using banker's rounding.
  constexpr int_type round() const { return value().round(); }

  /// Returns the integer part (which is the same as trunc()).
  constexpr int_type integer()  const { return value().integer(); }
  /// Returns the fractional part.
  constexpr int_type fraction() const { return value().fraction(); }

  /// Addition operator.
  /// @param c the value to add
  /// @return @c *this
  constexpr currency& operator+=(currency c);
  /// Subtraction operator.
  /// @param c the value to subtract
  /// @return @c *this
  constexpr currency& operator-=(currency c);
  /// Multiplication operator.
  /// @param m the value to multiply
  /// @return @c *this
  constexpr currency& operator*=(value_type m);
  /// Multiplication operator.
  /// @param m the value to multiply
  /// @return @c *this
  constexpr currency& operator*=(int_type m);
  /// Division operator.
  /// @param m the divisor
  /// @return @c *this
  constexpr currency& operator/=(value_type m);
  /// Division operator.
  /// @param m the divisor
  /// @return @c *this
  constexpr currency& operator/=(int_type m);

  /// Negate this value.
  constexpr void negate();

  /// Pre-increment operator.
  constexpr currency& operator++();
  /// Post-increment operator.
  constexpr currency operator++(int);
  /// Pre-decrement operator.
  constexpr currency& operator--();
  /// Post-decrement operator.
  constexpr currency operator--(int);

  /// Returns the internal value.
  constexpr value_type value()    const { return value_; }

  /// Returns a reference to the locale.
  constexpr std::locale const& locale() const { return locale_; }
  /// Sets a new locale.
  constexpr void locale(std::locale loc) { locale_ = loc; }
private:
  value_type value_;
  std::locale locale_;
};

template<class T, int N>
std::string currency<T,N>::to_string()
const
{
  // The locale has a fixed number of decimal places, which may be
  // different from the currency type. The digits string must
  // contain the correct number of digits for the locale's
  // expectation of the number of decimal places.
  // For example currency of 12.34 maps digits 123
  // if the locale has one decimal place or 12340 if
  // the locale has three.
  auto digits{ std::to_string(value().value()) };
  // Get punct facet and number of implicit decimal places.
  auto const& punct{ std::use_facet<std::moneypunct<char>>(locale()) };
  auto frac_digits{ punct.frac_digits() };
  // Add zeroes or drop digits as needed.
  if (N < frac_digits)
	digits.append(frac_digits - N, '0');
  else if (N > frac_digits)
    // TODO: round-off instead of truncate
    digits.erase(digits.end() - (N - frac_digits), digits.end());

  std::ostringstream out;
  out.imbue(locale());
  out << std::showbase;
  out << std::put_money(digits);
  return out.str();
}

template<class T, int N>
constexpr currency<T,N>& currency<T,N>::operator+=(currency f)
{
  value_ += f.value();
  return *this;
}

template<class T, int N>
constexpr currency<T,N>& currency<T,N>::operator-=(currency f)
{
  value_ -= f.value();
  return *this;
}

template<class T, int N>
constexpr currency<T,N>& currency<T,N>::operator*=(value_type i)
{
  value_ *= i;
  return *this;
}
template<class T, int N>
constexpr currency<T,N>& currency<T,N>::operator*=(int_type i)
{
  value_ *= i;
  return *this;
}

template<class T, int N>
constexpr currency<T,N>& currency<T,N>::operator/=(value_type i)
{
  value_ /= i;
  return *this;
}
template<class T, int N>
constexpr currency<T,N>& currency<T,N>::operator/=(int_type i)
{
  value_ /= i;
  return *this;
}

template<class T, int N>
constexpr void currency<T,N>::negate()
{
  value_ = -value_;
}

template<class T, int N>
constexpr currency<T,N>& currency<T,N>::operator++()
{
  ++value_;
  return *this;
}

template<class T, int N>
constexpr currency<T,N> currency<T,N>::operator++(int)
{
  currency result(*this);
  ++value_;
  return result;
}

template<class T, int N>
constexpr currency<T,N>& currency<T,N>::operator--()
{
  --value_;
  return *this;
}

template<class T, int N>
constexpr currency<T,N> currency<T,N>::operator--(int)
{
  currency result(*this);
  --value_;
  return result;
}

template<class T, int N>
template<class CharT, class Traits>
void currency<T,N>::read(std::basic_istream<CharT,Traits>& strm)
{
  // money_get() stores in digits only digits with an implied
  // decimal place that is determined by the locale.
  // The decimal place may differ from that of the currency type.
  std::string digits;
  strm >> std::get_money(digits);

  // So parse the digits based on the locale and
  // insert a decimal point for the fixed class to parse.

  // Get the facet that tells us the number of decimal places.
  auto const& punct{ std::use_facet<std::moneypunct<char>>(locale()) };

  // Set fraction to the rightmost frac_digits() characters of digits.
  digits.insert(digits.end() - punct.frac_digits(), '.');
  std::istringstream digit_stream{digits};
  value_.read(digit_stream);
}

/// Read a currency value
/// @param strm The input stream
/// @param[out] c Store the value here
template<class T, int N, class Char, class Traits>
std::basic_istream<Char, Traits>& operator>>(std::basic_istream<Char, Traits>& strm, currency<T,N>& c)
{
  c.read(strm);
  return strm;
}

/// Write a currency value
/// @param strm The output stream
/// @param c The value to write
template<class T, int N, class Char, class Traits>
std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& strm, currency<T,N> c)
{
  typename std::basic_ostream<Char, Traits>::sentry sentry(strm);
  strm << c.to_string();
  return strm;
}

/// Negate a currency value
template<class T, int N>
constexpr currency<T,N> operator-(currency<T,N> a)
{
  a.negate();
  return a;
}

/// Add currency values
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr currency<T,N> operator+(currency<T,N> a, currency<T,N> b)
{
  a += b;
  return a;
}

/// Subtract currency values
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr currency<T,N> operator-(currency<T,N> a, currency<T,N> b)
{
  a -= b;
  return a;
}

/// Multiply currency value and an integer
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr currency<T,N> operator*(currency<T,N> a, T b)
{
  a *= b;
  return a;
}

/// Multiply currency value and an integer
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr currency<T,N> operator*(T a, currency<T,N> b)
{
  b *= a;
  return b;
}

/// Divide currency value by an integer
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr currency<T,N> operator/(currency<T,N> a, T b)
{
  a /= b;
  return a;
}

/// Divide currency values to yield a rational result.
/// @param n the numerator
/// @param d the denominator
template<class T, int N>
constexpr rational<T> operator/(currency<T,N> n, currency<T,N> d)
{
  // Extract the underlying value of the fixed values. No adjustment
  // to scaling is needed because the numerator and denominator are
  // both scaled to the same amount.
  return rational<T>(n.value().value(), d.value().value());
}

/// Compare currency values for equality by comparing the underlying values.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator==(currency<T,N> a, currency<T,N> b)
{
  return a.value() == b.value();
}
/// Compare currency value and an integer for equality
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator==(currency<T,N> a, T b)
{
  return a.value() == b;
}
/// Compare currency value and an integer for equality
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator==(T a, currency<T,N> b)
{
  return a == b.value();
}

/// Compare currency values for inequality.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator!=(currency<T,N> a, currency<T,N> b)
{
  return not (a == b);
}
/// Compare currency value and an integer for inequality
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator!=(currency<T,N> a, T b)
{
  return not (a == b);
}
/// Compare currency value and an integer for inequality
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator!=(T a, currency<T,N> b)
{
  return not (a == b);
}

/// Compare currency values for less-than by comparing the underlying values.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator<(currency<T,N> a, currency<T,N> b)
{
  return a.value() < b.value();
}
/// Compare a currency value and an integer for less-than.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator<(currency<T,N> a, T b)
{
  return a.value() < b;
}
/// Compare a currency value and an integer for less-than.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator<(T a, currency<T,N> b)
{
  return a < b.value();
}

/// Compare currency values for greater-than.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator>(currency<T,N> a, currency<T,N> b)
{
  return b < a;
}
/// Compare a currency value and an integer for greater-than.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator>(currency<T,N> a, T b)
{
  return b < a;
}
/// Compare a currency value and an integer for greater-than.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator>(T a, currency<T,N> b)
{
  return b < a;
}

/// Compare currency values for less-than-or-equal.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator<=(currency<T,N> a, currency<T,N> b)
{
  return not (b < a);
}
/// Compare a currency value and an integer for less-than-or-equal.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator<=(currency<T,N> a, T b)
{
  return not (b < a);
}
/// Compare a currency value and an integer for less-than-or-equal.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator<=(T a, currency<T,N> b)
{
  return not (b < a);
}

/// Compare currency values for greater-than-or-equal.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator>=(currency<T,N> a, currency<T,N> b)
{
  return not (a < b);
}
/// Compare a currency value and an integer for greater-than-or-equal.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator>=(currency<T,N> a, T b)
{
  return not (a < b);
}
/// Compare a currency value and an integer for greater-than-or-equal.
/// @param a The left-hand operand
/// @param b The right-hand operand
template<class T, int N>
constexpr bool operator>=(T a, currency<T,N> b)
{
  return not (a < b);
}

#endif
