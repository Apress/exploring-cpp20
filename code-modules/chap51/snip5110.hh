/** @file snip5110.hh */
/** Code Snippet 51-10 */
int x{10};
long y{20};
std::cout << std::min<long>(x, y); // okay: compiler converts x to type long
