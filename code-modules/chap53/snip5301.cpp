#include <iostream>

struct integer
{
  void clear_sign_bit() {
    if (x < 0) x = -x;
  }
  int x;
};

#include "snip5301.hh"

int main()
{
  integer i{-42};
  i = absval(i);
  std::cout << i.x << '\n';
}
