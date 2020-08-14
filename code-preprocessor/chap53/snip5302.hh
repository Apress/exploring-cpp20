/** @file snip5302.hh */
/** Code Snippet 53-2 */
template<class T>
rational<T> absval(rational<T> const& r)
{
  if (r.numerator() < 0) // to avoid unnecessary multiplications in operator<
    return -r;
  else
    return r;
}
