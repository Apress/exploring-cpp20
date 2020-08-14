/** @file list6508.cpp */
/** Listing 65-8. Alternative Style of Accessing Command-Line Arguments */
import <iostream>;
import <string_view>;

int main(int, char **argv)
{
    if (argv[1] != nullptr) {
        if (std::string_view{argv[1]} == "--help")
            std::cout << "usage: " << argv[0] << " [ARGS...]";
        else {
            std::cout << *++argv;
            while (*++argv != nullptr)
                std::cout << ' ' << *argv;
        }
    }
    std::cout << '\n';        
}
