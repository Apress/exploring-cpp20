/** @file list5205.cpp */
/** Listing 52-5. Testing rational Comparison Operator */
import <iostream>;
import rational;

int main()
{
  static const rational<int> zero{};
  rational<int> r{};
  while (std::cin >> r)
    if (r != zero)
      std::cout << r << '\n';
}
