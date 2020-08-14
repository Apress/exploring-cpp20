#include <iostream>
#include "rational.hpp"
#include "list4902.hh"
#include "list4909.hh"
int main() {
  rational r{1,2};
  std::cout << r++ << '\n';
  std::cout << r-- << '\n';
  std::cout << r << '\n';
}
