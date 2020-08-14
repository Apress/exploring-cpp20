#include <concepts>
#include <iostream>
#include "snip5505.hh"

template<class T>
requires std::integral<T>
class rational {};

int main() {
  rational<long> r;
  return sizeof(r) == 0;
}
