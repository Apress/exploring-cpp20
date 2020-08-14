/** @file list4607.cpp */
/** Listing 46-7. Revealing the Implementation of reverse_iterator */
#include <algorithm>
#include <iostream>

#include "data.hpp"
#include "sequence.hpp"

int main()
{
  intvector data(10);
  std::generate(data.begin(), data.end(), sequence(1));
  write_data(data);                               // prints { 1 2 3 4 5 6 7 8 9 10 }
  intvector::iterator iter{data.begin()};
  iter = iter + 4;                                // iter is contiguous
  std::cout << *iter << '\n';                     // prints 5

  intvector::reverse_iterator rev{data.rbegin()};
  std::cout << *rev << '\n';                      // prints 10
  rev = rev + 4;                                  // rev is also contigious
  std::cout << *rev << '\n';                      // prints 6
  std::cout << *rev.base() << '\n';               // prints 7
  std::cout << *data.rend().base() << '\n';       // prints 1
}
