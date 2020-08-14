/** @file list3203.cpp */
/** Listing 32-3. Testing the I/O Operators */
#include <cassert>
import <iostream>;
import <numeric>;
import <sstream>;

// ... omitted for brevity ...

#include "list3203.inc0"

/// Tests for failbit only
bool iofailure(std::istream& in)
{
  return in.fail() and not in.bad();
}

int main()
{
  rational r{0};

  while (std::cin)
  {
    if (std::cin >> r)
      // Read succeeded, so no failure state is set in the stream.
      std::cout << r << '\n';
    else if (not std::cin.eof())
    {
      // Only failbit is set, meaning invalid input. Clear the state, 
      // and then skip the rest of the input line.
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
  }

  if (std::cin.bad()) 
    std::cerr << "Unrecoverable input failure\n";
}
