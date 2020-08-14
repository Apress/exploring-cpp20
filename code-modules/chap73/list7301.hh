/** @file list7301.hh */
/** Listing 73-1. Adding constexpr Throughout the rational Class Template */
export module numeric;

import <concepts>;
import <iostream>;
import <numeric>;
import <sstream>;
import <stdexcept>;

export template<class T>
requires std::integral<T>
class rational
{
public:
   using value_type = T;
   constexpr rational() : rational{0} {}
   constexpr rational(value_type num) : numerator_{num}, denominator_{1} {}
   constexpr rational(value_type num, value_type den)
   : numerator_{num}, denominator_{den}
   {
      reduce();
   }

   constexpr value_type numerator() const { return numerator_; }
   constexpr value_type denominator() const { return denominator_; }

   constexpr rational& operator*=(rational const& rhs) {
      numerator_ *= rhs.numerator_;
      denominator_ *= rhs.denominator_;
      reduce();
      return *this;
   }
   constexpr rational& operator/=(rational const& rhs) {
      numerator_ *= rhs.denominator_;
      denominator_ *= rhs.numerator_;
      reduce();
      return *this;
   }

//    ... every member function can be constexpr

#include "list7301.inc0"

private:
   constexpr void reduce() {
      if (denominator_ == 0)
         throw std::invalid_argument{"denominator is zero"};
      if (denominator_ < 0)
      {
         denominator_ = -denominator_;
         numerator_ = -numerator_;
      }
      auto div{std::gcd(numerator_, denominator_)};
      numerator_ = numerator_ / div;
      denominator_ = denominator_ / div;
   }

   value_type numerator_;
   value_type denominator_;
};

export template<class T>
constexpr bool operator==(rational<T> const& lhs, rational<T> const& rhs)
{
    return lhs.numerator() == rhs.numerator() and 
           lhs.denominator() == rhs.denominator();
}

// Every free function except I/O can be constexpr
export template<class T, class Ch, class Tr>
std::basic_ostream<Ch,Tr>& operator<<(std::basic_ostream<Ch, Tr>& stream, rational<T> const& r)
{
   std::basic_ostringstream<Ch,Tr> tmp;
   tmp << r.numerator() << '/' << r.denominator();
   return stream << tmp.str();
}
