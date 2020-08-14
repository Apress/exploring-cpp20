/** @file list2205.hh */
/** Listing 22-5. Testing for Palindromes */
bool is_palindrome(std::string_view str)
{
  auto half{ str.size() / 2 };
  auto letters_only{ str | std::views::filter(letter) };
  auto reversed{ letters_only | std::views::reverse | std::views::take(half) };
  return std::ranges::equal(letters_only | std::views::take(half), reversed);
}
