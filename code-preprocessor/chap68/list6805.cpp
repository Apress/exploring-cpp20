#include <cassert>
#include <iostream>
#include "rational.hpp"
#include "list6805.hh"

int main()
{
  rational<int> r1{1,2};
  rational<int> r2{1,3};
  assert(std::strong_ordering::greater == (r1 <=> r2));
  assert(std::strong_ordering::equal == (r1 <=> r1));
  assert(std::strong_ordering::less == (r2 <=> r1));
  assert(r2 < r1);
  assert(not(r1 < r2));
}
