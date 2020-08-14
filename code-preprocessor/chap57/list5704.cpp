/** @file list5704.cpp */
/** Listing 57-4. Testing the erase_less Function Template */
#include <algorithm>
#include <iostream>
#include <initializer_list>
#include <iterator>
#include <ranges>
#include <vector>

#include "erase_unsorted.hpp" // Listing 57-3

/// Print items from a container to the standard output.
template<class Container>
requires std::ranges::range<Container>
void print(std::string const& label, Container const& container)
{
  std::cout << label;
  using value_type = std::ranges::range_value_t<Container>;
  std::ranges::copy(container,
       std::ostream_iterator<value_type>(std::cout, " "));
  std::cout << '\n';
}

/// Test erase_less by extracting integers from a string into a container
/// and calling erase_less. Print the container before and after.
/// Double-check that the same results obtain with a list and a vector.
void test(std::initializer_list<int> numbers)
{
  std::vector<int> data{numbers};
  erase_unsorted(data);
  if (not std::is_sorted(data.begin(), data.end()))
      print("FAILED", data);
}

int main()
{
  test({2, 3, 7, 11, 13, 17, 23, 29, 31, 37});
  test({37, 31, 29, 23, 17, 13, 11, 7, 3, 2});
  test({});
  test({42});
  test({10, 30, 20, 40, 0, 50});
}
