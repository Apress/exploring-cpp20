/** @file list1104.cpp */
/** Listing 11-4. Rewriting the for Loop */
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

  for (auto start{data.begin()}, end{data.end()};
       start != end and start != --end;
       ++start)
  {
      std::iter_swap(start, end);
  }

  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
