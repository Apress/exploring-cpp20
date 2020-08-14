#include <iostream>
#include "rat2.hpp"
int main() {
  rational r{2,4};
  std::cout << r.numerator() << '/' << r.denominator() << '\n';
}
