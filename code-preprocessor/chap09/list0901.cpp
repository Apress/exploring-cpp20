/** @file list0901.cpp */
/** Listing 9-1. Sorting Integers */
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> data{};     // initialized to be empty
  int x{};

  // Read integers one at a time.
  while (std::cin >> x)
    // Store each integer in the vector.
    data.emplace_back(x);

  // Sort the vector.
  std::ranges::sort(data);

  // Print the vector, one number per line.
  for (int element : data)
    std::cout << element << '\n';
}
