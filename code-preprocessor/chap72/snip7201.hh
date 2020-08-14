/** @file snip7201.hh */
/** Code Snippet 72-1 */
rational reciprocal(rational const& r)
{
  return rational{r.denominator(), r.numerator()};
}
rational half{ reciprocal(2) };
