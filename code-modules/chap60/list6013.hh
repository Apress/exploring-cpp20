/** @file list6013.hh */
/** Listing 60-13. Demonstrating the Use of to_string */
import <iostream>;
import to_string;
import from_string;

int main()
{
    std::string str{
      to_string<int, char, std::char_traits<char>, std::allocator<char>>(42)
    };
    int value{from_string<int>(str)};
    std::cout << value << '\n';
}
