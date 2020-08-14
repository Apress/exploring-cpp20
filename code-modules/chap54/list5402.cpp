#include <iostream>
#include "list5401.hh"
#include "list5402.hh"

int main()
{
  pair<void,void> a, b;
  a = b;
  std::cout << sizeof(a) << '\n';
}
