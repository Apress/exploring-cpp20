#include <iostream>
#include "list6011.hh"
int main() {
  std::string s{ to_string(42) };
  std::string t{ to_string(4.2) };
  std::cout << s << '\n' << t << '\n';
}
