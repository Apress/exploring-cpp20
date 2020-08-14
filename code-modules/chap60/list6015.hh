/** @file list6015.hh */
/** Listing 60-15. Improving the Calling Interface of to_string */
import <ostream>;
import <sstream>;

template<class String, class T>
requires
  requires(T value, std::ostream stream) {
    stream << value;
    typename String::value_type;
    typename String::traits_type;
  }
String to_string(T const& obj)
{
  std::basic_ostringstream<typename String::value_type,
                           typename String::traits_type> out{};
  out << obj;
  return out.str();
}
