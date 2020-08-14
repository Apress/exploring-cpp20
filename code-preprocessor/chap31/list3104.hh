/** @file list3104.hh */
/** Listing 31-4. Implementing the > and >= Operators in Terms of < */
/// Compares two rational numbers for greater-than.
inline bool operator>(rational const& a, rational const& b)
{
  return b < a;
}

/// Compares two rational numbers for greater-than-or-equal.
inline bool operator>=(rational const& a, rational const& b)
{
  return not (b > a);
}
