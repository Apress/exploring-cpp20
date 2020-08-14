/** @file list4507.cpp */
/** Listing 45-7. Using lower_bound to Create a Sorted Vector */
#include <algorithm>
#include <iostream>
#include <ranges>

#include "data.hpp"

int main()
{
  intvector data{};
  int value;
  while (std::cin >> value)
  {
    auto lb{std::lower_bound(data.begin(), data.end(), value)};
    auto ub{std::upper_bound(data.begin(), data.end(), value)};
    if (lb == ub)
        // Not in data, so insert.
        data.insert(ub, value);
    // else value is already in the vector
  }
  write_data(data);
}
