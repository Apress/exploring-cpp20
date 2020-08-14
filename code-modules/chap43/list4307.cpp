/** @file list4307.cpp */
/** Listing 43-7. A Trivial Demonstration of globals.hpp */
#include <iostream>
#include "globals.hpp"

int main()
{
  std::cout << "Welcome to " << program_name << ' ' << program_version << '\n';
  std::cout << program_credits;
}
