/** @file list4104.cpp */
/** Listing 41-4. Finding the Longest String in a Data Set */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> data{ 
    std::istream_iterator<std::string>(std::cin),
    std::istream_iterator<std::string>() 
  };

  // Ensure at least one string to measure.
  if (data.empty()) data.emplace_back();
  auto longest{ std::ranges::max(data,
    [](std::string const& a, std::string const& b)
    {
      return a.size() < b.size();
    })
  };
  std::cout << "Longest string is \"" << longest << "\"\n";
}
