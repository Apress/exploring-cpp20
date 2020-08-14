/** @file list0601.cxx */
/** Listing 6-1. Deliberate Errors */
#include <iostream>
// Look for errors
int main()
{
  std::cout << "This program prints a table of squares.\n"
         "Enter the starting value for the table: ";
  int start{0};
  std::cin >> start;
  std::cout << "Enter the ending value for the table: ";
  int end(start);
  std::cin >> end;
  std::cout << "#   #^2\n";
  int x{start};
  end = end + 1; // exit loop when x reaches end 
  while (x != end)
  {
    std::cout << x << "   " << x*x << "\n";
    x = x + 1;
  }
}
