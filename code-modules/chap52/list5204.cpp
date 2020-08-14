/** @file list5204.cpp */
/** Listing 52-4. Simple I/O Test of the rational Class Template */
import <iostream>;
import rational;

int main()
{
  rational<int> r{};
  while (std::cin >> r)
    std::cout << r << '\n';
}
