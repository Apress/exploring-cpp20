// copied from list2403.cpp, but times lamba changed to #include
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
   std::vector<int> data{ 1, 2, 3 };

   int multiplier{3};
   auto times = 
#include "snip2406.hh"

   std::ranges::transform(data, data.begin(), times);

   multiplier = 20;
   std::ranges::transform(data, data.begin(), times);

   std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
