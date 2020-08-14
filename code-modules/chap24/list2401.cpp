/** @file list2401.cpp */
/** Listing 24-1. Calling transform to Apply a Lambda to Each Element of an Array */
import <iostream>;
import <iterator>;
import <ranges>;

int main()
{
   auto data{ std::ranges::istream_view<int>(std::cin)
              | std::views::transform([](int i) { return i * 2; })
              | std::views::transform([](int i) { return i + 3; })
   };
   for (auto element : data)
      std::cout << element << '\n';
}
