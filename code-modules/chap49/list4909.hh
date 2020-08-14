/** @file list4909.hh */
/** Listing 49-9. Postfix Increment and Decrement Operators */
rational rational::operator++(int)
{
  rational result{*this};
  numerator_ += denominator_;
  return result;
}

rational rational::operator--(int)
{
  rational result{*this};
  numerator_ -= denominator_;
  return result;
}
