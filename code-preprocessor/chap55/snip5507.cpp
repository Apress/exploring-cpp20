#include <iostream>
#include <limits>
#include <string>

#include "snip5507.hh"

template<class T>
requires any_integral<T>
void f(T i)
{
   std::cout << i << '\n';
}

void f(...)
{}

class Int {
public:
   Int(std::string s) : s_{std::move(s)} {}
   void print(std::ostream& stream) const {
    stream << s_;
   }
private:
   std::string s_;
};

std::ostream& operator<<(std::ostream& stream, Int const& i)
{
   i.print(stream);
   return stream;
}

namespace std {
template<>
struct numeric_limits<Int>
{
  static constexpr bool is_specialized = true;
  static constexpr bool is_integer = true;
};
} // std

int main()
{
   int i{1};
   long l{2};
   Int x{"12345"};
   f(i);
   f(l);
   f(x);
}
