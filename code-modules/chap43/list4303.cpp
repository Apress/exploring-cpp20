/** @file list4303.cpp */
/** Listing 43-3. The main Function Using the rational Class in the main.cpp File */
#include <iostream>
#include "rational.hpp"

int main()
{
  rational pi{3927, 1250};
  std::cout << "pi approximately equals " << pi << '\n';
}
