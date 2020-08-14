#include "rational.hpp"
#include <cmath>
#include "list3111.hh"
int main() {
    rational r{-1, 2};
    auto absr{ absval(r) };
    std::cout << absr.numerator << '/' << absr.denominator << '\n';
}
