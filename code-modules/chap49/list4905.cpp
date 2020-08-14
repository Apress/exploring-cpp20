#include "rational.hpp"
#include "list4901.hh"
#include "list4905.hh"
int main() {
    rational r{10, 4};
    r *= r;
    std::cout << r << '\n';
}
