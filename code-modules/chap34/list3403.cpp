/** @file list3403.cpp */
/** Listing 34-3. Using a Class and Its Members */
import <iostream>;

struct point
{
  double x;
  double y;
};

int main()
{
  point origin{}, unity{};
  origin.x = 0;
  origin.y = 0;
  unity.x = 1;
  unity.y = 1;
  std::cout << "origin = (" << origin.x << ", " << origin.y << ")\n";
  std::cout << "unity  = (" << unity.x  << ", " << unity.y  << ")\n";
}
