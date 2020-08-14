/** @file list4502.hpp */
/** Listing 45-2. The data Module to Support Integer Data */
export module data;

import <algorithm>;
import <iostream>;
import <iterator>;
export import <vector>;

/// Convenient shorthand for a vector of integers.
export using intvector = std::vector<int>;

/// Read a series of integers from the standard input into @p data,
/// overwriting @p data in the process.
/// @param[in,out] data a vector of integers
export void read_data(intvector& data)
{
  data.clear();
  data.insert(data.begin(), std::istream_iterator<int>(std::cin),
                            std::istream_iterator<int>());
}

/// Write a vector of integers to the standard output. Write all values on one
/// line, separated by single space characters, and surrounded by curly braces,
/// e.g., { 1 2 3 }.
/// @param data a vector of integers
export void write_data(intvector const& data)
{
  std::cout << "{ ";
  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "}\n";
}
