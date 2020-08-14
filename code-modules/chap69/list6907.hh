/** @file list6907.hh */
/** Listing 69-7. Using mix-in Class Template */
import <iostream>;
import <string>;
import <utility>;

import mixin; // Listing 69-6

class thing: public assignment_mixin<thing> {
public:
   thing() : value_{} {}
   thing(std::string s) : value_{std::move(s)} {}
   void swap(thing& other) { value_.swap(other.value_); }
   constexpr std::string const& str() const noexcept { return value_; }
private:
   std::string value_;
};

int main()
{
   thing one{};
   thing two{"two"};
   one = two;
   std::cout << one.str() << '\n';
}
