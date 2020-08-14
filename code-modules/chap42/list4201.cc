/** @file list4201.cc */
/** Listing 42-1. Writing a Module */
export module hello;
import <iostream>;
export void world()
{
    std::cout << "hello, world\n";
}
