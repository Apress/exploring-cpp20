/** @file list5902.hh */
/** Listing 59-2. Changing is_palindrome to a Function Template */
#include <ranges>
#include <string_view>

/** Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * Empty strings are not palindromes because that's just too easy.
 * @param str the string to test
 * @return true if @p str is the same forward and backward
 */
template<class Char, class Traits>
bool is_palindrome(std::basic_string_view<Char, Traits> str)
{
  auto letters_only{ str | std::views::filter(isletter<Char>) };
  auto reversed{ letters_only | std::ranges::views::reverse };
  return std::equal(
    std::ranges::begin(letters_only), std::ranges::end(letters_only),
    std::ranges::begin(reversed),     std::ranges::end(reversed),
    same_char<Char>);
}
