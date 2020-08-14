/** @file list1501.cpp */
/** Listing 15-1. Counting Occurrences of Unique Words */
import <iostream>;
import <map>;
import <string>;

int main()
{
  std::map<std::string, int> counts{};
  std::string word{};
  while (std::cin >> word) 
    ++counts[word];
  // TODO: Print the results.
}
