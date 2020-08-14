/** @file list3905.cpp */
/** Listing 39-5. Using the New movie Class */
#include <iostream>
#include <string>
#include <string_view>

// All of Listing 39-1 belongs here
// All of Listing 39-3 belongs here
// All of Listing 39-4 belongs here
// ... omitted for brevity ...

#include "list3905.inc0"

int main()
{
  book sc{"1", "The Sun Also Crashes", "Ernest Lemmingway", 2000};
  book ecpp{"2", "Exploring C++", "Ray Lischner", 2006};
  periodical pop{"3", "Popular C++", 13, 42, "January 1, 2000"};
  periodical today{"4", "C++ Today", 1, 1, "January 13, 1984"};
  movie tr{"5", "Lord of the Token Rings", 314};

  std::cout << sc << '\n';
  std::cout << ecpp << '\n';
  std::cout << pop << '\n';
  std::cout << today << '\n';
  std::cout << tr << '\n';
}
