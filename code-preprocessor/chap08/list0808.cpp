/** @file list0808.cpp */
/** Listing 8-8. Printing a Multiplication Table Using the format Function */
#include <format>
#include <iostream>

int main()
{
  int constexpr low{1};        ///< Minimum value for the table
  int constexpr high{10};      ///< Maximum value for the table
  int constexpr colwidth{4};   ///< Fixed width for all columns

  // First print the header.
  std::cout << std::format("{1:>{0}c}|", colwidth, '*');
  for (int i{low}; i <= high; i = i + 1)
    std::cout << std::format("{1:{0}}", colwidth, i);
  std::cout << '\n';

  // Print the table rule by using the fill character.
  std::cout << std::format("{2:->{0}}+{2:->{1}}\n", 
       colwidth, (high-low+1) * colwidth, "");

  // For each row...
  for (int row{low}; row <= high; row = row + 1)
  {
    std::cout << std::format("{1:{0}}|", colwidth, row);
    // Print all the columns.
    for (int col{low}; col <= high; col = col + 1)
      std::cout << std::format("{1:{0}}", colwidth, row * col);
    std::cout << '\n';
  }
}
