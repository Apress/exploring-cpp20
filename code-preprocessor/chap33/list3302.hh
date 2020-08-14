/** @file list3302.hh */
/** Listing 33-2. Assignment Operator with Explicit Use of this-> */
rational& operator=(rational const& that)
{
  this->numerator = that.numerator;
  this->denominator = that.denominator;
  reduce();
  return *this;
}
