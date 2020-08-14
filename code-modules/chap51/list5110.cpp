#include <iostream>
#include <iterator>
#include <vector>
#include "list5110.hh"

int main()
{
  std::vector<int> inp{ 1, 2, 3, 4 };
  std::vector<int> out{};
  copy(inp, std::back_inserter(out));
  for (auto x : out) std::cout << x << '\n';
}
