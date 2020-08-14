/** @file list4807.hh */
/** Listing 48-7. Throwing an Exception for a Zero Denominator */
export module rational;
import <stdexcept>;
import <string>;

export class rational
{
public:
  class zero_denominator : public std::logic_error
  {
  public:
    using std::logic_error::logic_error;
  };

  rational() : rational{0} {}
  rational(int num) : numerator_{num}, denominator_{1} {}
  rational(int num, int den) : numerator_{num}, denominator_{den}
  {
    if (denominator_ == 0)
      throw zero_denominator{"zero denominator"};
    reduce();
  }
// ... omitted for brevity ...

#include "list4807.inc0"
};
