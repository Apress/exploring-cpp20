/** @file list6805.hh */
/** Listing 68-5. Implementing three-way comparison for rational */
#include <compare>

template<class T>
std::strong_ordering operator<=>(rational<T> const& lhs, rational<T> const& rhs)
{
  if (lhs.denominator() == rhs.denominator())
    // The easy case.
    return lhs.numerator() <=> rhs.numerator();
  else
    return lhs.numerator()*rhs.denominator() <=> lhs.denominator()*rhs.numerator();
}

template<class T>
bool operator<(rational<T> const& lhs, rational<T> const& rhs)
{
  return std::strong_ordering::less == (lhs <=> rhs);
}
