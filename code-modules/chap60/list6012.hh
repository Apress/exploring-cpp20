/** @file list6012.hh */
/** Listing 60-12. Rewriting to_string As a Template Function */
import <ostream>;
import <sstream>;
import <string>;

template<class T, class Char, class Traits, class Allocator>
requires
  requires(T value, std::ostream stream) {
    stream << value;
  }
std::basic_string<Char, Traits, Allocator> to_string(T const& obj)
{
  std::basic_ostringstream<Char, Traits> out{};
  out << obj;
  return out.str();
}
