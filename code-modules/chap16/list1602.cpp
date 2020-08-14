/** @file list1602.cpp */
/** Listing 16-2. Counting Words, Moving a Definition Inside an if Statement */
import <iostream>;
import <map>;
import <string>;

int main()
{
  using count_map = std::map<std::string,int>;
  using count_iterator = count_map::iterator;

  count_map counts{};

  // Read words from the standard input and count the number of times
  // each word occurs.
  std::string word{};
  while (std::cin >> word)
    ++counts[word];

  if (count_iterator the{counts.find("the")}; the == counts.end())
    std::cout << "\"the\": not found\n";
  else if (the->second == 1)
    std::cout << "\"the\": occurs " << the->second << " time\n";
  else
    std::cout << "\"the\": occurs " << the->second << " times\n";
}
