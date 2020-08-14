#include <iostream>

#include "parse.hpp"

/** @mainpage
 * This is step 1 of the calculator project in Exploration 68 of <em>Exploring C++:
 * The Programmer's Introduction to C++</em>.
 *
 * This version of the calculator implements simple arithmetic. It uses a recursive-descent
 * parser and immediately evaluates expressions using @c double for all values.
 */
int main()
{
  parse_loop(std::cin, std::cout);
}
