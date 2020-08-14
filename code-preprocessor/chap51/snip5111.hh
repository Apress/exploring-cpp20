/** @file snip5111.hh */
/** Code Snippet 51-11 */
template<class T, class R>
T convert(R const& r)
{
  return static_cast<T>(r.numerator()) / r.denominator();
}
