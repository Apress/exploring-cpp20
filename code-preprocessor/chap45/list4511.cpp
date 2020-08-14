/** @file list4511.cpp */
/** Listing 45-11. Using replace_if and a Lambda to Replace All Integers in [10, 20] with 0 */
#include <algorithm>
#include <ranges>

#include "data.hpp"

int main()
{
  intvector data{};
  read_data(data);
  write_data(data);
  std::ranges::replace_if(data, [](int x) { return x >= 10 and x <= 20; }, 0);
  write_data(data);
}
