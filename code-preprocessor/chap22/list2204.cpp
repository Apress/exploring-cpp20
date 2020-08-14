/** @file list2204.cpp */
/** Listing 22-4. Sorting into Descending Order */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

/** Predicate for sorting into descending order. */
int descending(int a, int b)
{
  return a > b;
}

int main()
{
  std::vector<int> data{std::istream_iterator<int>(std::cin),
                        std::istream_iterator<int>()};

  std::ranges::sort(data, descending);

  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
