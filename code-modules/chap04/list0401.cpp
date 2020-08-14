/** @file list0401.cpp */
/** Listing 4-1. Different Styles of String Output */
import <iostream>;

int main()
{
   std::cout << "Shape\tSides\n" << "-----\t-----\n";
   std::cout << "Square\t" << 4 << '\n' <<
                "Circle\t?\n";
}
