/** @file list5804.cpp */
/** Listing 58-4. Counting Words Again, This Time with Cached Facets */
#include <format>
#include <iostream>
#include <locale>
#include <map>
#include <ranges>
#include <string>
#include <string_view>

using count_map  = std::map<std::string, int>;  ///< Map words to counts
using count_pair = count_map::value_type;       ///< pair of a word and a count
using str_size   = std::string::size_type;      ///< String size type

void initialize_streams()
{
  std::cin.imbue(std::locale{});
  std::cout.imbue(std::locale{});
}

class sanitizer
{
public:
  sanitizer(std::locale const& locale) 
  : ctype_{ std::use_facet<std::ctype<char>>(locale) }
  {}

  bool keep(char ch) const { return ctype_.is(ctype_.alnum, ch); }
  char tolower(char ch) const { return ctype_.tolower(ch); }

  std::string operator()(std::string_view str)
  const
  {
    auto data{ str
      | std::ranges::views::filter([this](char ch) { return keep(ch); })
      | std::ranges::views::transform([this](char ch) { return tolower(ch); })  };
    return std::string{ std::ranges::begin(data), std::ranges::end(data) };
  }
private:
    std::ctype<char> const& ctype_;
};

str_size get_longest_key(count_map const& map)
{
  str_size result{0};
  for (auto const& pair : map)
    if (pair.first.size() > result)
      result = pair.first.size();
  return result;
}

void print_pair(count_pair const& pair, str_size longest)
{
  int constexpr count_size{10}; // Number of places for printing the count
  std::cout << std::format("{0:{1}} {2:{3}}\n", pair.first, longest, pair.second, count_size);
}

void print_counts(count_map const& counts)
{
  auto longest{get_longest_key(counts)};
  
  // For each word/count pair...
  for (count_pair pair: counts)
    print_pair(pair, longest);
}

int main()
{
  // Set the global locale to the native locale.
  std::locale::global(std::locale{""});
  initialize_streams();

  count_map counts{};
  sanitizer sanitize{std::locale{""}};

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
