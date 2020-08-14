/** @file list1001.cpp */
/** Listing 10-1. Demonstrating the std::ranges::copy Function */
#include <cassert>
#include <algorithm>
#include <vector>

int main()
{
  std::vector<int> input{ 10, 20, 30 };
  std::vector<int> output{};
  output.resize(input.size());
  std::ranges::copy(input, output.begin());
  // Now output has a complete copy of input.
  assert(input == output);
}
