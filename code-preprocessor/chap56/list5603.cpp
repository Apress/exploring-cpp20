#include <iostream>
#include "list5601.hh"
#include "list5602.hh"
#include "list5603.hh"
int main() {
  return sizeof(numeric::fixed<int,1>) * sizeof(numeric::rational<int>) == 0;
}
