/** @file list6016.hh */
/** Listing 60-16. Making to_string Too Complicated */
import <iostream>;
import <sstream>;

template<class String, class T>
requires
  requires(T value, std::ostream stream) {
    stream << value;
    typename String::value_type;
    typename String::traits_type;
  }
String to_string(T const& obj,
  std::ios_base::fmtflags flags = std::ios_base::fmtflags{},
  int width = 0,
  char fill = ' ')
{
  std::basic_ostringstream<typename String::value_type,
                           typename String::traits_type> out{};
  out.flags(flags);
  out.width(width);
  out.fill(fill);
  out << obj;
  return out.str();
}
