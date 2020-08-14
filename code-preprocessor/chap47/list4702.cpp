/** @file list4702.cpp */
/** Listing 47-2. Demonstrating Range Functions */
#include <iostream>
#include <ranges>

int main()
{
    std::cout << "Enter an integer: ";
    int input{};
    if (std::cin >> input)
    {
        for (auto x : std::ranges::single_view{input}) {
            std::cout << x << '\n';
        }
    }
}
