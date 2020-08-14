#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>
int main() {
#include "snip4710.hh"
std::ranges::copy(demo1, std::ostream_iterator<int>(std::cout, " ")); std::cout << '\n';
std::ranges::copy(demo2, std::ostream_iterator<int>(std::cout, " ")); std::cout << '\n';
std::ranges::copy(demo3, std::ostream_iterator<int>(std::cout, " ")); std::cout << '\n';
std::ranges::copy(demo4, std::ostream_iterator<int>(std::cout, " ")); std::cout << '\n';
}
