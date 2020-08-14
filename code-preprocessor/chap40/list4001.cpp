/** @file list4001.cpp */
/** Listing 40-1. Computing BMI */
#include <iostream>

using height = int;
using weight = int;
using bmi = int;

bmi compute_bmi(height h, weight w)
{
  return w * 10000 / (h * h);
}

int main()
{
  std::cout << "Height in centimeters: ";
  height h{};
  std::cin >> h;

  std::cout << "Weight in kilograms: ";
  weight w{};
  std::cin >> w;

  std::cout << "Bogus Metabolic Index = " << compute_bmi(w, h) << '\n';
}
