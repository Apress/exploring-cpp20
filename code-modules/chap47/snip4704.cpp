#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main() {
#include "snip4704.hh"
std::ranges::copy(sentence, std::ostreambuf_iterator(std::cout));
std::cout << '\n';
}
