/** @file list6402.cpp */
/** Listing 64-2. Moving Strings Instead of Copying Them */
import <iostream>;
import <string>;
import <utility>;
import <vector>;

class mystring : public std::string
{
public:
   mystring() : std::string{} { std::cout << "mystring()\n"; }
   mystring(mystring const& copy) : std::string{copy} {
      std::cout << "mystring copy(\"" << *this << "\")\n";
   }
   mystring(mystring&& move) noexcept
   : std::string{std::move(move)} {
      std::cout << "mystring move(\"" << *this << "\")\n";
   }
};

std::vector<mystring> read_data()
{
   std::vector<mystring> strings{};
   mystring line{};
   while (std::getline(std::cin, line))
      strings.emplace_back(std::move(line));
   return strings;
}

int main()
{
   std::vector<mystring> strings;
   strings = read_data();
}
