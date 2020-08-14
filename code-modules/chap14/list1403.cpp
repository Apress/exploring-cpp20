/** @file list1403.cpp */
/** Listing 14-3. Copying Integers, with Minimal Error-Checking */
#include <cerrno>
import <algorithm>;
import <fstream>;
import <iostream>;
import <ranges>;
import <system_error>;

int main()
{
  std::ifstream in{"list1403.in"};
  if (not in)
    std::cerr << "list1403.in: " <<
      std::generic_category().message(errno) << '\n';
  else
  {
    std::ofstream out{"list1403.out"};
    if (out) {
      std::ranges::copy(std::ranges::istream_view<int>(in),
        std::ostream_iterator<int>{out, "\n"});
      out.close();
    }
    if (not out)
      std::cerr << "list1403.out: " <<
        std::generic_category().message(errno) << '\n';
  }
}
