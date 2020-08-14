/** @file list7003.cpp */
/** Listing 70-3. Using Character Traits When Copying Input to Output */
import <iostream>;
import <string>;        // for char_traits

int main()
{
   using char_traits = std::char_traits<char>; // for brevity and clarity
   char_traits::int_type c{};
   while (c = std::cin.get(), not char_traits::eq_int_type(c, char_traits::eof()))
      std::cout.put(char_traits::to_char_type(c));
}
