/** @file list1401.cpp */
/** Listing 14-1. Copying Integers from a File to Standard Output */
#include <cerrno>
import <algorithm>;
import <fstream>;
import <iostream>;
import <iterator>;
import <system_error>;

int main()
{
  std::ifstream in{"list1401.in"};
  if (not in)
    std::cerr << "list1401.in: " <<
      std::generic_category().message(errno) << '\n';
  else
  {
    std::ranges::copy(std::ranges::istream_view<int>(in),
        std::ostream_iterator<int>{std::cout, "\n"});
    in.close();
  }
}
