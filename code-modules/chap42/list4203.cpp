#include <iostream>
#include "rat1.hpp"
int main() {
  rational r{2,4};
  std::cout << r.numerator() << '/' << r.denominator() << '\n';
}
