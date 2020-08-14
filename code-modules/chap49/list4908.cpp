#include <iostream>
#include "rational.hpp"
#include "list4902.hh"
#include "list4908.hh"
int main() {
  rational r{1,2};
  ++r;
  std::cout << r << '\n';
}
