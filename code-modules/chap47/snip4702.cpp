#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <ranges>
int main() {
#include "snip4702.hh"
std::ranges::copy(ring, std::ostreambuf_iterator(std::cout));
std::cout << '\n';
}
