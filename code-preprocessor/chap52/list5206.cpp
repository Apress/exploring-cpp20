#include "rational.hpp"
#include "list5206.hh"

int main()
{
   rational n{710};
   rational d{226};
   n /= d;
   std::cout << n << '\n';
}
