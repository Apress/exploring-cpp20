/** @file list1402.cpp */
/** Listing 14-2. Copying Integers from a Named File to a Named File */
#include <cerrno>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <system_error>

int main()
{
  std::ifstream in{"list1402.in"};
  if (not in)
    std::cerr << "list1402.in: " <<
      std::generic_category().message(errno) << '\n';
  else
  {
    std::ofstream out{"list1402.out"};
    if (not out)
      std::cerr << "list1402.out: " <<
        std::generic_category().message(errno) << '\n';
    else
    {
      std::ranges::copy(std::ranges::istream_view<int>(in),
        std::ostream_iterator<int>{out, "\n"});
      out.close();
      in.close();
    }
  }
}
