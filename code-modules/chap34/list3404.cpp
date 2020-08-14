#include <iostream>
#include "list3404.hh"
int main() {
  point a;
  a.x = 1.0;
  a.y = 1.0;
  a.scale(2.5);
  std::cout << a.x << ',' << a.y << '\n';
  a.scale(2.0, 3.0);
  std::cout << a.x << ',' << a.y << '\n';
  a.offset(-1.0);
  std::cout << a.x << ',' << a.y << '\n';
  a.offset(2.0, 3.0);
  std::cout << a.x << ',' << a.y << '\n';
  std::cout << a.angle() << '\n';
  std::cout << a.distance() << '\n';
}
