/** @file list6709.cpp */
/** Listing 67-9. Mixing Signed and Unsigned Integers */
#include <iostream>
void show(unsigned u)
{
   std::cout << u << '\n';
}

int main()
{
   int i{-1};
   std::cout << i << '\n';
   show(i);
}
