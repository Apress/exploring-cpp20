/** @file list1304.cxx */
/** Listing 13-4. Mystery Function */
#include <cassert>
import <algorithm>;
import <iostream>;
import <iterator>;
import <ranges>;
import <string>;
import <vector>;

int main()
{
  int v{};
  std::vector<int> data{};
  std::vector<int>::iterator i{}, p{};
  std::string s{};

  std::ranges::copy(std::ranges::istream_view<int>(std::cin),
            std::back_inserter(data));
  i = data.begin();

  while (i != data.end())
  {
    v = *i;
    p = std::lower_bound(data.begin(), i, v);
    if (i == p)
      ++i;
    else
    {
      i = data.erase(i);
      data.insert(p, v);
    }
  }

  s = " ";
  for (p = i, i = data.begin(); i != data.end(); p = i, ++i)
  {
    if (p != data.end())
      assert(not (*i < *p));
  }

  std::cout << '{';
  for (i = data.begin(); i != data.end(); ++i)
  {
    v = *p;
    std::cout << s << v;
    s = ", ";
  }
  std::cout << " }\n";
}
