#include <iostream>
#include "list5301.hh"
int main()
{
  std::cout << std::boolalpha <<
    is_void<int>::value << '\n' <<
    is_void<void>::value << '\n';
}
