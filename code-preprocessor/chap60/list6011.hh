/** @file list6011.hh */
/** Listing 60-11. The to_string Function Converts a Value to a String */
#include <ostream>
#include <sstream>
#include <string>

template<class T>
requires
  requires(T value, std::ostream stream) {
    stream << value;
  }
std::string to_string(T const& obj)
{
  std::ostringstream out{};
  out << obj;
  return out.str();
}
