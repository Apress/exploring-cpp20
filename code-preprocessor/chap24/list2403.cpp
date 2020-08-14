/** @file list2403.cpp */
/** Listing 24-3. Using a Lambda to Access Local Variables */
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
   std::vector<int> data{ 1, 2, 3 };

   int multiplier{3};
   auto times = [multiplier](int i) { return i * multiplier; };

   std::ranges::transform(data, data.begin(), times);

   multiplier = 20;
   std::ranges::transform(data, data.begin(), times);

   std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
