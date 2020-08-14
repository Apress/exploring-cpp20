/** @file list2501.cpp */
/** Listing 25-1. Printing Vectors by Using Overloaded Functions */
#include <iostream>
#include <string_view>
#include <vector>

void print(int i)
{
  std::cout << i;
}

void print(int i, int width)
{
  std::cout.width(width);
  std::cout << i;
}

void print(std::vector<int> const& vec,
    int width,
    std::string_view prefix,
    std::string_view separator,
    std::string_view postfix)
{
  std::cout << prefix;

  bool print_separator{false};
  for (auto x : vec)
  {
    if (print_separator)
      std::cout << separator;
    else
      print_separator = true;
    print(x, width);
  }

  std::cout << postfix;
}

void print(std::vector<int> const& vec,
    std::string_view prefix,
    std::string_view separator,
    std::string_view postfix)
{
  print(vec, 0, prefix, separator, postfix);
}

int main()
{
  std::vector<int> data{ 10, 20, 30, 40, 100, 1000, };


  std::cout << "columnar data:\n";
  print(data, 10, "", "\n", "\n");
  std::cout << "row data:\n";
  print(data, "{", ", ", "}\n");
}
