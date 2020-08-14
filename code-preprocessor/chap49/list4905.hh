/** @file list4905.hh */
/** Listing 49-5. Implementing the Multiplication Assignment Operator */
rational const& rational::operator*=(rational const& rhs)
{
  numerator_ *= rhs.numerator();
  denominator_ *= rhs.denominator();
  reduce();
  return *this;
}
