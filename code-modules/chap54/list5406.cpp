#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "list5407.hh"
#include "list5406.hh"

template<class T, int N>
std::ostream& operator<<(std::ostream& stream, fixed<T, N> const& f)
{
   f.print(stream);
   return stream;
}

int main() {
   fixed<long, 4> f{12, 345};
   std::cout << f << '\n';
}
