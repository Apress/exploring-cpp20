/** @file list2203.hh */
/** Listing 22-3. Sanitizing a String by Transforming and Filtering It */
/** Test whether to keep a letter.
 * @param ch the character to test
 * @return true to keep @p ch because it may be a character that makes up a word
 */
bool keep(char ch)
{
  return std::isalnum(ch, std::locale{});
}

/** Convert to lowercase.
 * @param ch the character to test
 * @return the character converted to lowercase
 */
char lowercase(char ch)
{
  return std::tolower(ch, std::locale{});
}

/** Sanitize a string by keeping only alphabetic characters.
 * @param str the original string
 * @return a sanitized copy of the string
 */
std::string sanitize(std::string_view str)
{
  auto data{ str
             | std::views::filter(keep)
             | std::views::transform(lowercase)  };
  return std::string{ std::ranges::begin(data), std::ranges::end(data) };
}
