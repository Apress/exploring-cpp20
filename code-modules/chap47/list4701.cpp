/** @file list4701.cpp */
/** Listing 47-1. Demonstrating Range Functions */
import <algorithm>;
import <iostream>;
import <ranges>;
import <vector>;

int main()
{
   std::vector<int> data;
   std::cout << "Enter some numbers:\n";
   std::ranges::copy(std::ranges::istream_view<int>(std::cin),
       std::back_inserter(data));

    std::cout << "You entered " << std::ranges::size(data) << " values\n";
    if (not std::ranges::empty(data))
    {
       std::ranges::sort(data);
       auto start{ std::ranges::cbegin(data) };
       auto middle{ start + std::ranges::size(data) / 2 };
       std::cout << "The median value is " << *middle << '\n';
    }
}
