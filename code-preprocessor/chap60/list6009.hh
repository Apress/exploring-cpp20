/** @file list6009.hh */
/** Listing 60-9. The from_string Function Extracts a Value from a String */
#include <istream>
#include <sstream>
#include <stdexcept>
#include <string>

template<class T>
requires
  requires(T value, std::istream stream) {
    stream >> value;
  }
T from_string(std::string const& str)
{
  std::istringstream in{str};
  T result{};
  if (in >> result)
    return result;
  else
    throw std::runtime_error{str};
}
