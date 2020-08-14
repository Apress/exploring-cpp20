/** @file list1102.cxx */
/** Listing 11-2. Erroneous Program That Applies Decrement to an Output Iterator */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main()
{
  std::vector<int> data;
  std::ranges::copy(std::ranges::istream_view<int>(std::cin),
                    std::back_inserter(std::cout));
  std::ranges::sort(data);
  std::ostream_iterator<int> output{ std::cout, "\n" };
  --output;
  std::ranges::copy(input, output);
}
