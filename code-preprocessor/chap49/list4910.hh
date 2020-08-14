/** @file list4910.hh */
/** Listing 49-10. The rational Class Definition */
// export module rat;
#include <iostream>
#include <stdexcept>

/// Represent a rational number (fraction) as a numerator and denominator.
/*export*/ class rational
{
public:
  class zero_denominator : public std::logic_error
  {
  public:
    using std::logic_error::logic_error;
  };
  rational() noexcept : rational{0} {}
  rational(int num) noexcept : numerator_{num}, denominator_{1} {}
  rational(int num, int den);
  rational(double r);

  int numerator()              const noexcept { return numerator_; }
  int denominator()            const noexcept { return denominator_; }
  float as_float()             const;
  double as_double()           const;
  long double as_long_double() const;

  // optimization to avoid an unneeded call to reduce()
  rational const& operator=(int) noexcept;

  rational const& operator+=(rational const& rhs);
  rational const& operator-=(rational const& rhs);
  rational const& operator*=(rational const& rhs);
  rational const& operator/=(rational const& rhs);
  rational const& operator++();
  rational const& operator--();
  rational operator++(int);
  rational operator--(int);

private:
  /// Reduce the numerator and denominator by their GCD.
  void reduce();
  /// Reduce the numerator and denominator, and normalize the signs of both,
  /// that is, ensure denominator is not negative.
  void normalize();
  /// Return an initial value for denominator_. Throw a zero_denominator
  /// exception if @p den is zero. Always return a positive number.
  int init_denominator(int den);
  int numerator_;
  int denominator_;
};

/*export*/ rational abs(rational const& r);
/*export*/ rational operator-(rational const& r);
/*export*/ rational operator+(rational const& lhs, rational const& rhs);
/*export*/ rational operator-(rational const& lhs, rational const& rhs);
/*export*/ rational operator*(rational const& lhs, rational const& rhs);
/*export*/ rational operator/(rational const& lhs, rational const& rhs);

/*export*/ bool operator==(rational const& a, rational const& b);
/*export*/ bool operator<(rational const& a, rational const& b);

/*export*/ inline bool operator!=(rational const& a, rational const& b)
{
  return not (a == b);
}

/*export*/ inline bool operator<=(rational const& a, rational const& b)
{
  return not (b < a);
}

/*export*/ inline bool operator>(rational const& a, rational const& b)
{
  return b < a;
}

/*export*/ inline bool operator>=(rational const& a, rational const& b)
{
  return not (b > a);
}

/*export*/ std::istream& operator>>(std::istream& in, rational& rat);
/*export*/ std::ostream& operator<<(std::ostream& out, rational const& rat);
