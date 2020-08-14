#include <iostream>
#include "rational.hpp"

#include "snip5302.hh"

int main()
{
   rational r{-84, 2};
   r = absval(r);
   std::cout << r << '\n';
}
