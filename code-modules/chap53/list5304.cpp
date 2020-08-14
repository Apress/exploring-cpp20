#include <iostream>
#include "list5304.hh"

int main()
{
   less<int> const x;
   if (x(1, 2)) std::cout << "success\n";
   else std::cout << "fail\n";
}
