/** @file list5103.cpp */
/** Listing 51-3. Testing the absval Function Template */
import <iostream>;
import rational;  // Listing 49-10

template<class T>
T absval(T x)
{
  if (x < 0)
    return -x;
  else
    return x;
}

int main()
{
  std::cout << absval(-42) << '\n';
  std::cout << absval(-4.2) << '\n';
  std::cout << absval(42) << '\n';
  std::cout << absval(4.2) << '\n';
  std::cout << absval(-42L) << '\n';
  std::cout << absval(rational{42, 5}) << '\n';
  std::cout << absval(rational{-42, 5}) << '\n';
  std::cout << absval(rational{42, -5}) << '\n';
}
