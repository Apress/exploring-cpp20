/** @file list1204.cpp */
/** Listing 12-4. Using Short-Circuiting to Test for Nonzero Vector Elements */
import <algorithm>;
import <iostream>;
import <iterator>;
import <ranges>;
import <vector>;

int main()
{
  std::vector<int> data{};
  std::ranges::copy(std::ranges::istream_view<int>(std::cin),
              std::back_inserter(data));

  auto iter{data.begin()}, end{data.end()};
  for (; iter != end and *iter == 0; ++iter)
    /*empty*/;
  if (iter == end)
    std::cout << "data contains all zeroes\n";
  else
    std::cout << "data does not contain all zeroes\n";
}
