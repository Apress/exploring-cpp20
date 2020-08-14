#include <iostream>
#include "snip5601.hh"

namespace exploring_cpp { namespace numeric {
template<class T>
rational<T> operator+(rational<T>, T)
{
  return rational<T>{};
}

}}

template<class T>
std::ostream& operator<<(std::ostream& stream, exploring_cpp::numeric::rational<T> const&)
{
  return stream;
}

int main() {
#include "snip5610.hh"
}
