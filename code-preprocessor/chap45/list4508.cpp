/** @file list4508.cpp */
/** Listing 45-8. Exploring the lower_bound and upper_bound Functions */
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include "data.hpp"

int main()
{
  intvector data{};
  read_data(data);
  std::ranges::sort(data);
  write_data(data);

  for (int test : { 3, 4, 8, 0, 10 })
  {
    auto lb{std::lower_bound(data.begin(), data.end(), test)};
    auto ub{std::upper_bound(data.begin(), data.end(), test)};
    std::cout << "bounds of " << test << ": { "
         << std::distance(data.begin(), lb) << ", "
         << std::distance(data.begin(), ub) << " }\n";
  }
}
