// Copied from list2202.cpp, but sanitize() replaced by #include.

#include <algorithm>
#include <format>
#include <iostream>
#include <locale>
#include <map>
#include <ranges>
#include <string>

using count_map  = std::map<std::string, int>;  ///< Map words to counts
using count_pair = count_map::value_type;       ///< pair of a word and a count
using str_size   = std::string::size_type;      ///< String size type

/** Initialize the I/O streams by imbuing them with
 * the global locale. Use this function to imbue the streams
 * with the native locale. C++ initially imbues streams with
 * the classic locale.
 */
void initialize_streams()
{
  std::cin.imbue(std::locale{});
  std::cout.imbue(std::locale{});
}

/** Find the longest key in a map.
 * @param map the map to search
 * @returns the size of the longest key in @p map
 */
str_size get_longest_key(count_map const& map)
{
  str_size result{0};
  for (auto pair : map)
    if (pair.first.size() > result)
      result = pair.first.size();
  return result;
}

/** Print the word, count, newline. Keep the columns neatly aligned.
 * Rather than the tedious operation of measuring the magnitude of all
 * the counts and then determining the necessary number of columns, just
 * use a sufficiently large value for the counts column.
 * @param pair a word/count pair
 * @param longest the size of the longest key; pad all keys to this size
 */
void print_pair(count_pair const& pair, str_size longest)
{
  int constexpr count_size{10}; // Number of places for printing the count
  std::cout << std::format("{1:{0}}{3:{2}}\n",
          longest, pair.first, count_size, pair.second);
}

/** Print the results in neat columns.
 * @param counts the map of all the counts
 */
void print_counts(count_map const& counts)
{
  str_size longest{get_longest_key(counts)};
  
  // For each word/count pair...
  for (count_pair pair: counts)
    print_pair(pair, longest);
}

#include "list2303.hh"

/** Main program to count unique words in the standard input. */
int main()
{
  // Set the global locale to the native locale.
  std::locale::global(std::locale{""});
  initialize_streams();

  count_map counts{};

  // Read words from the standard input and count the number of times
  // each word occurs.
  std::string word{};
  while (std::cin >> word)
  {
    std::string copy{sanitize(word)};

    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  print_counts(counts);
}
