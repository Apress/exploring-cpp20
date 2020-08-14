/** @file list3112.cpp */
/** Listing 31-12. Converting to Floating-Point Types */
#include <cassert>
import <iostream>;
import <numeric>;

struct rational
{
  float as_float()
  {
    return static_cast<float>(numerator) / denominator;
  }

  double as_double()
  {
    return numerator / static_cast<double>(denominator);
  }

  long double as_long_double()
  {
    return static_cast<long double>(numerator) / 
           static_cast<long double>(denominator);
  }

// ... omitted for brevity ...

#include "list3112.inc0"

};

int main()
{
  rational pi{355, 113};
  rational bmi{90*100*100, 180*180}; // Bogus-metabolic indicator of 90kg, 180cm
  double circumference{0}, radius{10};

  circumference = 2 * pi.as_double() * radius;
  std::cout << "circumference of circle with radius " << radius << " is about "
            << circumference << '\n';
  std::cout << "bmi = " << bmi.as_float() << '\n';
}
