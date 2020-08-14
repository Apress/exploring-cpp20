#include <iostream>
#include "list7004.hh"
#include "list7006.hh"
#include "list7007.hh"
#include "list7008.hh"
int main() {
    using string = mystring<char, array_storage<char, 256>>;
    string s;
    while (std::cin >> s) std::cout << '"' << s << "\"\n";
}
