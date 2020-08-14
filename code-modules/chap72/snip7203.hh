/** @file snip7203.hh */
/** Code Snippet 72-3 */
explicit operator float() const {
  return float(numerator()) / float(denominator());
}
