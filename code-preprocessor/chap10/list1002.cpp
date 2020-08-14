/** @file list1002.cpp */
/** Listing 10-2. Demonstrating the std::ostream_iterator Class */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> data;
  int element;
  while (std::cin >> element)
    data.emplace_back(element);

  std::ranges::sort(data);

  std::ranges::copy(data, std::ostream_iterator<int>{std::cout, "\n"});
}
