/** @file list4203.cc */
/** Listing 42-3. Defining the rational Class In a Module */
// export module rat1;
#include <cassert>
#include <numeric>
/*export*/ class rational
{
public:
  rational(int num) : numerator_{num}, denominator_{1} {}
  rational(rational const&) = default;
  inline rational(int num, int den);
  void assign(int num, int den);
  int numerator() const                   { return numerator_; }
  int denominator() const                 { return denominator_; }
  rational& operator=(int num);
private:
  void reduce();
  int numerator_;
  int denominator_;
};

inline rational::rational(int num, int den)
: numerator_{num}, denominator_{den}
{
  reduce();
}

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
