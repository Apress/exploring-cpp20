/** @file list1702.cpp */
/** Listing 17-2. Echoing Input to Output, One Character at a Time */
import <iostream>;

int main()
{
  std::cin >> std::noskipws;
  char ch{};
  while (std::cin >> ch)
    std::cout << ch;
}
