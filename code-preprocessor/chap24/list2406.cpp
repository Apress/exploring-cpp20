/** @file list2406.cpp */
/** Listing 24-6. Testing for Palindromes */
#include <algorithm>
#include <iostream>
#include <locale>
#include <ranges>
#include <string>
#include <string_view>

/** Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * Empty strings are not palindromes because that's just too easy.
 * @param str the string to test
 * @return true if @p str is the same forward and backward
 */
bool is_palindrome(std::string_view str)
{
  auto letters_only{ str
     | std::views::filter([](char c) { return std::isalnum(c, std::locale{}); })
     | std::views::transform([](char c) { return std::tolower(c, std::locale{}); })
  };
  auto reversed{ letters_only | std::views::reverse };
  return std::ranges::equal(letters_only, reversed);
}

int main()
{
  std::locale::global(std::locale{""});
  std::cin.imbue(std::locale{});
  std::cout.imbue(std::locale{});

  std::string line{};
  while (std::getline(std::cin, line))
    if (is_palindrome(line))
      std::cout << line << '\n';
}
