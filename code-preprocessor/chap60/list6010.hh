/** @file list6010.hh */
/** Listing 60-10. Enhancing the from_string Function */
#include <istream>
#include <sstream>
#include <stdexcept>
#include <string>

template<class T>
requires
  requires(T value, std::istream stream) {
    stream >> value;
  }
T from_string(std::string const& str, bool skipws = true)
{
  std::istringstream in{str};
  if (not skipws)
    in >> std::noskipws;
  T result{};
  char extra;
  if (not (in >> result))
    throw std::runtime_error{str};
  else if (in >> extra)
    throw std::runtime_error{str};
  else
    return result;
}
