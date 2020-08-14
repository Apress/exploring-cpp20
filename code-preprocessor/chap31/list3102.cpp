#include "rational_class.hpp"
#include "list3102.hh"
int main() {
  rational pi1{355, 113};
  rational pi2{1420, 452};

  if (pi1 == pi2)
    std::cout << "success\n";
  else
    std::cout << "failure\n";
}
