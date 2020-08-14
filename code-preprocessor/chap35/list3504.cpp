/** @file list3504.cpp */
/** Listing 35-4. Calling const and Non-const Member Functions */
#include <cmath>
#include <iostream>

// Use the same point definition as Listing 35-3
// ... omitted for brevity ...

#include "list3504.inc0"

void print_polar(point const& pt)
{
  std::cout << "{ r=" << pt.distance() << ", angle=" << pt.angle() << " }\n";
}

void print_cartesian(point const& pt)
{
  std::cout << "{ x=" << pt.x << ", y=" << pt.y << " }\n";
}

int main()
{
  point p1{}, p2{};
  double const pi{3.141592653589792};
  p1.x = std::cos(pi / 3);
  p1.y = std::sin(pi / 3);
  print_polar(p1);
  print_cartesian(p1);
  p2 = p1;
  p2.scale(4.0);
  print_polar(p2);
  print_cartesian(p2);
  p2.offset(0.0, -2.0);
  print_polar(p2);
  print_cartesian(p2);
}
