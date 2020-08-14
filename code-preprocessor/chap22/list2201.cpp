/** @file list2201.cpp */
/** Listing 22-1. Calling transform to Apply a Function to Each Element of a Range */
#include <iostream>
#include <iterator>
#include <ranges>

int times_two(int i)
{
  return i * 2;
}

int plus_three(int i)
{
  return i + 3;
}

int main()
{
   auto data{ std::ranges::istream_view<int>(std::cin)
              | std::ranges::views::transform(times_two)
              | std::ranges::views::transform(plus_three)
   };
   for (auto element : data)
      std::cout << element << '\n';
}
