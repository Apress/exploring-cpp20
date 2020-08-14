/** @file list2205.cpp */
/** Listing 22-5. Testing for Palindromes */
import <algorithm>;
import <iostream>;
import <locale>;
import <ranges>;
import <string>;
import <string_view>;

/** Test for letter.
 * @param ch the character to test
 * @return true if @p ch is a letter
 */
bool letter(char ch)
{
  return std::isalpha(ch, std::locale{});
}

/** Convert to lowercase.
 * @param ch the character to test
 * @return the character converted to lowercase
 */
char lowercase(char ch)
{
  return std::tolower(ch, std::locale{});
}

/** Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * Empty strings are not palindromes because that's just too easy.
 * @param str the string to test
 * @return true if @p str is the same forward and backward
 */
bool is_palindrome(std::string_view str)
{
  auto letters_only{ str | std::views::filter(letter) };
  auto lowercased{ letters_only | std::views::transform(lowercase) };
  auto reversed{ lowercased | std::views::reverse };
  return std::ranges::equal(lowercased, reversed);
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

