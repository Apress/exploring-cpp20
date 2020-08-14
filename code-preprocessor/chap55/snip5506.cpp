#include <concepts>
#include <iostream>
#include "snip5506.hh"

template<std::integral T>
class rational {};

int main() {
  rational<long> r;
  return sizeof(r) == 0;
}
