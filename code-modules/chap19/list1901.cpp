/** @file list1901.cpp */
/** Listing 19-1. Folding Uppercase to Lowercase Prior to Counting Words */
import <iostream>;
import <locale>;
import <map>;
import <string>;

int main()
{
  using count_map = std::map<std::string, int>;

  std::locale native{""};     // get the native locale
  std::cin.imbue(native);     // interpret the input and output according to
  std::cout.imbue(native);    // the native locale

  count_map counts{};
  std::string word{};

  // Read words from the standard input and count the number of times
  // each word occurs.
  while (std::cin >> word)
  {
    // Make a copy of word, keeping only alphabetic characters.
    std::string copy{};
    for (char ch : word)
      if (std::isalnum(ch, native))
        copy.push_back(tolower(ch, native));
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  // For each word/count pair, print the word & count on one line.
  for (auto pair : counts)
    std::cout << pair.first << '\t' << pair.second << '\n';
}
