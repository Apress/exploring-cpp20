#include <iostream>
#include "rational.hpp"
#include "snip5111.hh"

int main()
{
  rational r{355, 113};
  std::cout << convert<double>(r) << '\n';
}
