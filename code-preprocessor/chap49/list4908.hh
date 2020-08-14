/** @file list4908.hh */
/** Listing 49-8. The Prefix Increment Operator for rational */
rational const& rational::operator++()
{
  numerator_ += denominator_;
  return *this;
}
