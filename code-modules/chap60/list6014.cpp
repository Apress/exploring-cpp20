/** @file list6014.cpp */
/** Listing 60-14. Passing the Destination String As an Argument to to_string */
import <iostream>;
import <sstream>;
import <string>;
import from_string;

template<class T, class Char, class Traits, class Allocator>
requires
  requires(T value, std::ostream stream) {
    stream << value;
  }
void to_string(T const& obj, std::basic_string<Char, Traits, Allocator>& result)
{
  std::basic_ostringstream<Char, Traits> out{};
  out << obj;
  result = out.str();
}

int main()
{
    std::string str{};
    to_string(42, str);
    int value(from_string<int>(str));
    std::cout << value << '\n';
}
