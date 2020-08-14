/** @file list4506.cpp */
/** Listing 45-6. Finding a Sub-range That Matches the First Four Digits of π */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "data.hpp"
#include "randomint.hpp"

int main()
{
  intvector pi{ 3, 1, 4, 1 };
  intvector data(10000, 0);
  // The randomint functor generates random numbers in the range [0, 9].
  std::ranges::generate(data, randomint{0, 9});

  auto match{std::ranges::search(data, pi)};
  if (not match)
    std::cout << "The integer range does not contain the digits of pi.\n";
  else
  {
    std::cout << "Easy as pi: ";
    std::ranges::copy(match, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
  }
}
