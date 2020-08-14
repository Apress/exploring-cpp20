#include <iostream>
#include "list6802.hh"
int main() {
 enum x { a, b };
 return sizeof(enum_map<x>) == 0;
}
