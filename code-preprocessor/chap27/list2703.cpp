/** @file list2703.cpp */
/** Listing 27-3. Demonstrating Floating-Point Output */
#include <format>
#include <iostream>

/// Print a floating-point number in three different formats.
/// @param precision the precision to use when printing @p value
/// @param value the floating-point number to print
void print(int precision, float value)
{
  std::cout.precision(precision);
  std::cout << std::scientific << value << '\t'
            << std::fixed      << value << '\t'
            << std::hexfloat   << value << '\t';

  // Set the format to general.
  std::cout.unsetf(std::ios_base::floatfield);
  std::cout << value << '\n';

  std::cout << std::format("{0:.{1}e}\n{0:.{1}f}\n{0:.{1}a}\n{0:.{1}g}\n",
      value, precision);
}

/// Main program.
int main()
{
  print(6, 123456.789F);
  print(4, 1.23456789F);
  print(2, 123456789.F);
  print(5, -1234.5678e9F);
}
