/** @file list5901.hh */
/** Listing 59-1. Supporting Cast for the is_palindrome Function Template */
#include <locale>

template<class Char>
auto const& ctype{ std::use_facet<std::ctype<Char>>(std::locale()) };

/** Test for non-letter.
 * @param ch the character to test
 * @return true if @p ch is not a letter
 */
template<class Char>
bool isletter(Char ch)
{
  return ctype<Char>.is(std::ctype_base::alpha, ch);
}

/** Convert to lowercase.
 * @param ch the character to test
 * @return the character converted to lowercase
 */
template<class Char>
Char lowercase(Char ch)
{
  return ctype<Char>.tolower(ch);
}

/** Compare two characters without regard to case. */
template<class Char>
bool same_char(Char a, Char b)
{
  return lowercase(a) == lowercase(b);
}
