/** @file list2402.cpp */
/** Listing 24-2. Using a Lambda to Access Local Variables */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main()
{
   std::cout << "Multiplier: ";
   int multiplier{};
   std::cin >> multiplier;
 
   auto data{
      std::ranges::istream_view<int>(std::cin)
      | std::views::transform([multiplier](int i) { return i * multiplier; })
   };

   std::cout << "Data:\n";
   std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
