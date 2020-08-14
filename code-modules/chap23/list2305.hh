/** @file list2305.hh */
/** Listing 23-5. Testing for Palindromes */
/** Determine whether @p str is a palindrome.
 * Only letter characters are tested. Spaces and punctuation don't count.
 * @param str the string to test
 * @return true if @p str is the same forward and backward
 */
bool is_palindrome(std::string_view str)
{
  if (str.empty())
    return true;
  for (auto left{str.begin()}, right{str.end() - 1}; left < right;) {
    if (not letter(*left))
      ++left;
    else if (not letter(*right))
      --right;
    else if (lowercase(*left) != lowercase(*right))
      return false;
    else {
      ++left;
      --right;
    }
  }
  return true;
}
