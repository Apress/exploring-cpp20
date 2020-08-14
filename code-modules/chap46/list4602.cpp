/** @file list4602.cpp */
/** Listing 46-2. Advancing an Iterator */
import <algorithm>;
import <iostream>;
import <iterator>;
import <vector>;

import data;       // see Listing 45-2.
import sequence;   // see Listing 44-6.

int main()
{
  intvector data(10);
  // fill with even numbers
  std::generate(data.begin(), data.end(), sequence{0, 2}); 
  auto iter{data.begin()};
  std::advance(iter, 4);
  std::cout << *iter << ", ";
  iter = std::prev(iter, 2);
  std::cout << *iter << '\n';
}
