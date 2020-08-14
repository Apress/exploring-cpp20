#include <iostream>
#include "list6010.hh"
int main() {
  std::cout << from_string<int>("  42  ") << '\n'
            << from_string<int>("42", false) << '\n'
            << std::flush
            << from_string<int>("42.0") << '\n';
}
