/** @file list5206.hh */
/** Listing 52-6. Invoking a Default Constructor of a Template Parameter */
template<class T>
rational<T> const& rational<T>::operator/=(rational const& rhs)
{
  if (rhs.numerator() == T{})
      throw zero_denominator("divide by zero");
  numerator_ *= rhs.denominator();
  denominator_ *= rhs.numerator();
  if (denominator_ < T{})
  {
      denominator_ = -denominator_;
      numerator_ = -numerator_;
  }
  reduce();
  return *this;
}
