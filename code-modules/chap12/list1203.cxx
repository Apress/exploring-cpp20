/** @file list1203.cxx */
/** Listing 12-3. Converting a std::string to bool */
import <iostream>;
import <string>;

int main()
{
  std::string empty{};

  if (empty)
    std::cout << "empty is true\n";
  else
    std::cout << "empty is false\n";

}
