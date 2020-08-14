/** @file rational.hpp */
/** Listing 43-1. The Interface Header for rational in rational.hpp */
#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <iosfwd>
class rational
{
public:
  inline rational(int num) : numerator_{num}, denominator_{1} {}
  inline rational(rational const&) = default;
  inline rational(int num, int den)
  : numerator_{num}, denominator_{den}
  {
    reduce();
  }
  void assign(int num, int den);
  inline int numerator() const           { return numerator_; }
  inline int denominator() const         { return denominator_; }
  rational& operator=(int num);
private:
  void reduce();
  int numerator_;
  int denominator_;
};

std::ostream& operator<<(std::ostream&, rational const&);
#endif // RATIONAL_HPP_
