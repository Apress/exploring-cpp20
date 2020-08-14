/** @file list6803.hh */
/** Listing 68-3. Defining a Type That Maps Strings To and From Enumerations */
#include <istream>
#include <ostream>

template<class Enum>
std::istream& read(std::istream& stream, enum_map<Enum> const& map, Enum& value)
{
    std::string token;
    if (stream >> token)
    {
        value = map.at(token);
    }
    return stream;
}

template<class Enum>
std::ostream& write(std::ostream& stream, enum_map<Enum> const& map, Enum value)
{
    stream << map.at(value);
    return stream;
}
