/** @file list4204.cc */
/** Listing 42-4. Defining the rational Class In One Declaration In a Module */
export module rat2;
#include <cassert>
import <numeric>;
export class rational
{
public:
  inline rational(int num) : numerator_{num}, denominator_{1} {}
  inline rational(rational const&) = default;
  inline rational(int num, int den)
  : numerator_{num}, denominator_{den}
  {
    reduce();
  }
  void assign(int num, int den)
  {
    numerator_ = num;
    denominator_ = den;
    reduce();
  }
  inline int numerator() const           { return numerator_; }
  inline int denominator() const         { return denominator_; }
  rational& operator=(int num)
  {
    numerator_ = num;
    denominator_ = 1;
    return *this;
  }
private:
  void reduce()
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
  int numerator_;
  int denominator_;
};
