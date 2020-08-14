/** @file list6713.cpp */
/** Listing 67-13. Examples from the <bit> Module */
import <bit>;
import <iostream>;

int main()
{
    std::cout << std::hex << std::showbase <<
        "std::rotl(0x12345678U, 8) = " << std::rotl(0x12345678U, 8) <<
        "std::rotr(0x12345678U, 8) = " << std::rotr(0x12345678U, 8) <<
        std::dec <<
        "std::popcount(0x0110110U) = " << std::popcount(0x0110110U) <<
        "std::bit_width(0x00ffffU) = " << std::bit_width(0x00ffffU) <<
        '\n';
}
