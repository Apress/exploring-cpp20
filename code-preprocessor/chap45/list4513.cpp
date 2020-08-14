/** @file list4513.cpp */
/** Listing 45-13. Erasing Elements from a Vector */
#include <algorithm>
#include <iterator>
#include <ranges>

#include "data.hpp"
#include "intrange.hpp"

int main()
{
  intvector data{};
  read_data(data);
  // sort into descending order
  std::ranges::sort(data, [](int a, int b) { return b < a; });
  auto odd{ std::ranges::remove_if(data, [](int x) { return x % 2 == 0; }) };
  intvector uniquely_odd{};
  std::unique_copy(begin(data), begin(odd), std::back_inserter(uniquely_odd));
  write_data(uniquely_odd);
}
