/** @file list4603.cpp */
/** Listing 46-3. Demonstrating Iterator Member Types */
import <iostream>;
import <string>;
import <vector>;

int main()
{
  std::vector<std::string> lines{2, "hello"};

  std::vector<std::string>::iterator iter{lines.begin()};
  *iter = "good-bye";               // dereference and modify the first item
  std::size_t size{iter->size()};   // dereference and call a member function

  std::vector<std::string>::const_iterator citer{lines.cbegin()};
  std::cout << *citer << '\n';
  std::cout << size << '\n';
}
