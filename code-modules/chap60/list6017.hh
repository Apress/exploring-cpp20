/** @file list6017.hh */
/** Listing 60-17. Calling the Complicated Version of to_string */
import <iostream>;
import <string>;
import to_string;

int main()
{
  std::cout << to_string<std::string>(42, std::ios_base::hex) << '\n';
  std::cout << to_string<std::string>(42.0, std::ios_base::scientific, 10) << '\n';
  std::cout << to_string<std::string>(true, std::ios_base::boolalpha) << '\n';
}
