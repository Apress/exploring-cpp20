/** @file list1804.cpp */
/** Listing 18-4. Creating and Sharing a Single Locale Object */
import <iostream>;
import <locale>;
import <map>;
import <string>;

int main()
{
  using count_map = std::map<std::string, int>;

  std::locale native{""};         // Get the native locale.
  std::cin.imbue(native);         // Interpret the input and output according
  std::cout.imbue(native);        // to the native locale.

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
        copy.push_back(ch);
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  // For each word/count pair, print the word & count on one line.
  for (auto pair : counts)
    std::cout << pair.first << '\t' << pair.second << '\n';
}
