#include <iostream>
#include <limits>

template<class T>
struct rational {
  rational operator-() { return *this; }
};

#include "list5405.hh"

int main()
{
   std::cout << std::numeric_limits<rational<long long>>::digits << '\n';
}
