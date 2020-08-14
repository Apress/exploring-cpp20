#include <iomanip>
#include <iostream>
#include "list5407.hh"
#include "list5406.hh"
#include "list5408.hh"

template<class T, int N>
std::ostream& operator<<(std::ostream& stream, fixed<T, N> const& f)
{
   f.print(stream);
   return stream;
}

int main()
{
    fixed<long, 0> f{12, 3450};
    std::cout << f << '\n';
}
