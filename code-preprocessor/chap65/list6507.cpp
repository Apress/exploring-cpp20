/** @file list6507.cpp */
/** Listing 65-7. Demonstrating Command-Line Arguments */
#include <cstring>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (std::strcmp(argv[1], "--help") == 0)
            std::cout << "usage: " << argv[0] << " [ARGS...]";
        else {
            std::cout << argv[1];
            for (int argn{2}; argn < argc; ++argn)
                std::cout << ' ' << argv[argn];
        }
    }
    std::cout << '\n';        
}
