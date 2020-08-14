/** @file list5702.cpp */
/** Listing 57-2. Using a Hint Position When Inserting into a Set */
#include <iostream>
#include <set>
#include <string>

int main()
{
  std::set<std::string> words{};

  std::set<std::string>::iterator hint{words.begin()};
  std::string word{};
  while(std::cin >> word)
    hint = words.emplace_hint(hint, std::move(word));

  std::cout << "stored " << words.size() << " unique words\n";
}
