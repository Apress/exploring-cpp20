/** @file list4606.cxx */
/** Listing 46-6. Negating the Middle Value in a Series of Integers */
#include <iostream>
#include <iterator>
#include "data.hpp"

int main()
{
  intvector data{};
  read_data(data);
  intvector::const_iterator iter{data.begin()};
  std::advance(iter, data.size() / 2); // move to middle of vector
  if (not data.empty())
    *iter = -*iter;
  write_data(data);
}
