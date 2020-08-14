/** @file list1803.cpp */
/** Listing 18-3. Using the Native Locale for Output */
import <iostream>;
import <locale>;

int main()
{
  std::cout.imbue(std::locale{""});

  int sum{0};
  int x{};
  while (std::cin >> x)
    sum = sum + x;
  std::cout << "sum = " << sum << '\n';
}
