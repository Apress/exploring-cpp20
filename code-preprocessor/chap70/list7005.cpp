#include <iostream>
#include "list7004.hh"
#include "list7005.hh"
#include "list7007.hh"
#include "list7008.hh"
int main() {
    using string = mystring<char, vector_storage<char>>;
    string s;
    while (std::cin >> s) std::cout << '"' << s << "\"\n";
}
