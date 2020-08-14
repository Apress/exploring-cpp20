#include <iostream>
#include "list5701.hh"
int main() {
  rational<int> r{1,2};
  std::cout << std::hash<rational<int>>{}(r) << '\n';
}
