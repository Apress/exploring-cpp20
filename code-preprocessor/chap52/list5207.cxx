/** @file list5207.cxx */
/** Listing 52-7. Trying to Mix rational Base Types */
#include "rational.hpp"

int main()
{
  rational<int> little{};
  rational<long> big{};
  big = little;
}
