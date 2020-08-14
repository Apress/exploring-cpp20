#include <iostream>
#include <vector>
#include <concepts>

namespace sz {
#include "list5504.hh"
}

int main() {
   std::vector<int> data{ 1, 2, 3, 4, 5 };
   std::cout << sz::size(data) << '\n';
}
