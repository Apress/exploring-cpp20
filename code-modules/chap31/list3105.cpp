/** @file list3105.cpp */
/** Listing 31-5. Testing the rational Comparison Operators */
#include <cassert>

import <iostream>;
import <numeric>;
import test;

// ... struct rational omitted for brevity ...

#include "list3105.inc0"

int main()
{
  rational a{60, 5};
  rational b{12, 1};
  rational c{-24, -2};
  TEST(a == b);
  TEST(a >= b);
  TEST(a <= b);
  TEST(b <= a);
  TEST(b >= a);
  TEST(b == c);
  TEST(b >= c);
  TEST(b <= c);
  TEST(a == c);
  TEST(a >= c);
  TEST(a <= c);

  rational d{109, 10};
  TEST(d < a);
  TEST(d <= a);
  TEST(d != a);
  TEST(a > d);
  TEST(a >= d);
  TEST(a != d);

  rational e{241, 20};
  TEST(e > a);
  TEST(e >= a);
  TEST(e != a);
  TEST(a < e);
  TEST(a <= e);
  TEST(a != e);
}
