/** @file list4211.cpp */
/** Listing 42-11. Main Program Imports a, b, and c */
module;
import b;
import c;
import <iostream>;

int main()
{
   while (std::cin)
   {
      std::cout << "pi=" << pi << '\n';
      std::cout << "Radius=";
      double radius{};
      if (std::cin >> radius)
      {
         std::cout << "Area = " << area(radius) << '\n';
         std::cout << "Circumference = " << circumference(radius) << '\n';
      }
   }
}
