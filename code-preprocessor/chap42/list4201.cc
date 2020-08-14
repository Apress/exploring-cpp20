/** @file list4201.cc */
/** Listing 42-1. Writing a Module */
// export module hello;
#include <iostream>
/*export*/ void world()
{
    std::cout << "hello, world\n";
}
