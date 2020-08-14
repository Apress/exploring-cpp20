/** @file list1103.cpp */
/** Listing 11-3. Reversing the Input Order */
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

  for (auto start{data.begin()}, end{data.end()}; start != end; /*empty*/)
  {
    --end;
    if (start != end)
    {
      std::iter_swap(start, end);
      ++start;
    }
  }

  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
