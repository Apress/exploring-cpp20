#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>
#include "list5502.hh"

int main()
{
  std::vector<int> src{ 1,2,3,4 };
  std::vector<int> data;
  copy(src, std::back_inserter(data));
  std::cout << data.size() << '\n';
}
