#include "rational_class.hpp"
#include "list3103.hh"
#include "list3104.hh"
int main() {
  rational pi1{355, 113};
  rational pi2{1420, 452};

  if (pi1 >= pi2 and pi2 >= pi1)
    std::cout << "success\n";
  else
    std::cout << "failure\n";
}
