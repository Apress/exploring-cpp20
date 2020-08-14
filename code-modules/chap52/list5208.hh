/** @file list5208.hh */
/** Listing 52-8. Defining the Assignment Operator Function Template */
template<class T>
template<class U>
rational<T>& rational<T>::operator=(rational<U> const& rhs)
{
  assign(rhs.numerator(), rhs.denominator());
  return *this;
}
