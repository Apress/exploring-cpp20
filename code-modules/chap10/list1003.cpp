/** @file list1003.cpp */
/** Listing 10-3. Demonstrating the std::back_inserter Function */
import <algorithm>;
import <iostream>;
import <iterator>;
import <ranges>;
import <vector>;

int main()
{
  std::vector<int> data;
  std::ranges::copy(std::ranges::istream_view<int>(std::cin),
                    std::back_inserter(data));
  std::ranges::sort(data);
  std::ranges::copy(data, std::ostream_iterator<int>{std::cout, "\n"});
}
