/** @file list2404.cxx */
/** Listing 24-4. Using a Lambda to Access Local Variables */
import <iostream>;

int main()
{
   int x{0};
   auto lambda = [x](int y) {
      x = 1;
      y = 2;
      return x + y;
   };
   int local{0};
   std::cout << lambda(local) << ", " << x << ", " << local << '\n';

}
