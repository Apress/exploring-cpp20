/** @file list1801.cpp */
/** Listing 18-1. Counting Words: Restricting Words to Letters and Letter-Like Characters */
#include <format>
#include <iostream>
#include <map>
#include <string>

int main()
{
  using count_map = std::map<std::string, int>;
  using str_size  = std::string::size_type;

  count_map counts{};
  std::string word{};

  // Characters that are considered to be okay for use in words.
  // Split a long string into parts, and the compiler joins the parts.
  std::string okay{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "abcdefghijklmnopqrstuvwxyz"
                   "0123456789-_"};
  
  // Read words from the standard input and count the number of times
  // each word occurs.
  while (std::cin >> word)
  {
    // Make a copy of word, keeping only the characters that appear in okay.
    std::string copy{};
    for (char ch : word)
      if (okay.find(ch) != std::string::npos)
        copy.push_back(ch);
    // The "word" might be all punctuation, so the copy would be empty.
    // Don't count empty strings.
    if (not copy.empty())
      ++counts[copy];
  }

  // Determine the longest word.
  str_size longest{0};
  for (auto pair : counts)
    if (pair.first.size() > longest)
      longest = pair.first.size();
  
  // For each word/count pair...
  constexpr int count_size{10}; // Number of places for printing the count
  for (auto pair : counts)
    // Print the word, count, newline. Keep the columns neatly aligned.
    std::cout << std::format("{1:{0}}{3:{2}}\n",
        longest, pair.first, count_size, pair.second);
}
