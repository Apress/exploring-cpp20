/** @file snip6402.hh */
/** Code Snippet 64-2 */
using lvalue = int&;
using rvalue = int&&;
int i;
lvalue& ref1 = i;    // ref1 has type int&
lvalue&& ref2 = i;   // ref2 has type int& 
rvalue& ref3 = i;    // ref3 has type int&
rvalue&& ref4 = 42;  // ref4 has type int&&
