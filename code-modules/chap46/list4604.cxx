/** @file list4604.cxx */
/** Listing 46-4. Printing the Middle Item of a Series of Integers */
import <iostream>;
import <iterator>;
import data;

int main()
{
  intvector data{};
  read_data(data);
  const intvector::iterator iter{data.begin()};
  std::advance(iter, data.size() / 2); // move to middle of vector
  if (not data.empty())
    std::cout << "middle item = " << *iter << '\n';
}
