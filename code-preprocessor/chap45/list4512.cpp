/** @file list4512.cpp */
/** Listing 45-12. Shuffling Integers into Random Order */
#include <algorithm>
#include <random>

#include "data.hpp"
#include "sequence.hpp"

int main()
{
  intvector data(100);
  std::ranges::generate(data, sequence{1, 1});
  write_data(data);
  std::ranges::shuffle(data, std::default_random_engine{});
  write_data(data);
}
