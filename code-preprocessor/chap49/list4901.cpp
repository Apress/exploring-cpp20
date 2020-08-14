#include "rational.hpp"
#include "list4901.hh"
int main() {
    std::cout << rational{2, 1} << '\n';
    std::cout << rational{-2, 1} << '\n';
    std::cout << rational{2, -1} << '\n';
    std::cout << rational{-2, -1} << '\n';
    std::cout << std::flush;
    std::cout << rational{2, 0} << '\n';
}
