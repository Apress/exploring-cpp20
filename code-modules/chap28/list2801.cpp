/** @file list2801.cpp */
/** Listing 28-1. Documenting Your Code with Doxygen */
/** @file
 * @brief Tests strings to see whether they are palindromes.
 *
 * Reads lines from the input, strip non-letters, and checks whether
 * the result is a palindrome. Ignores case differences when checking.
 * Echoes palindromes to the standard output.
 */

/** @mainpage Palindromes
 * Tests input strings to see whether they are palindromes. 
 *
 * A _palindrome_ is a string that reads the same forward and backward.
 * To test for palindromes, this program needs to strip punctuation and
 * other non-essential characters from the string, and compare letters without
 * regard to case differences.
 *
 * This program reads lines of text from the standard input and echoes
 * to the standard output those lines that are palindromes.
 *
 * Source file: list2801.cpp
 *
 * @date 27-March-2020
 * @author Ray Lischner
 * @version 3.0
 */
import <algorithm>;
import <iostream>;
import <ranges>;
import <locale>;
import <ranges>;
import <string>;
import <string_view>;

/** @brief Tests for non-letter.
 *
 * Tests the character @p ch in the global locale.
 * @param ch the character to test
 * @return true if @p ch is not a letter
 */
bool non_letter(char ch)
{
  return not std::isalnum(ch, std::locale{});
}

/** @brief Converts to lowercase.
 *
 * All conversions use the global locale.
 *
 * @param ch the character to test
 * @return the character converted to lowercase
 */
char lowercase(char ch)
{
  return std::tolower(ch, std::locale{});
}

/** @brief Compares two characters without regard to case.
 *
 * @param a one character to compare
 * @param b the other character to compare
 * @return `true` if the characters are the same in lowercase,
 *         `false` if they are different.
 */
bool is_same_char(char a, char b)
{
  return lowercase(a) == lowercase(b);
}

/** @brief Determines whether @p str is a palindrome.
 *
 * Only letter characters are tested. Spaces and punctuation don't count.
 * Empty strings are not palindromes because that's just too easy.
 * @param str the string to test
 * @return `true` if @p str is the same forward and backward and
 *     `not str.empty()`
 */
bool is_palindrome(std::string_view str)
{
  auto filtered_str{ str | std::views::filter(lowercase) };
  return std::ranges::equal(filtered_str, filtered_str|std::views::reverse,
      is_same_char);
}

/** @brief Main program.
 * Sets the global locale to the user's native locale.
 * Then imbues the I/O streams with the native locale.
 */
int main()
{
  std::locale::global(std::locale{""});
  std::cin.imbue(std::locale{});
  std::cout.imbue(std::locale{});

  for (std::string line{}; std::getline(std::cin, line); /*empty*/)
    if (is_palindrome(line))
      std::cout << line << '\n';
}
