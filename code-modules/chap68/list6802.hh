/** @file list6802.hh */
/** Listing 68-2. Defining a Type That Maps Strings To and From Enumerations */
export module enums;

import <algorithm>;
import <initializer_list>;
import <stdexcept>;
import <string>;
import <type_traits>;
import <unordered_map>;

export template<class T>
concept is_enum = std::is_enum_v<T>;

export template<class Enum>
requires is_enum<Enum>
class enum_map : public std::unordered_map<std::string, Enum>
{
public:
    using enum_type = Enum;
    using super = std::unordered_map<std::string, enum_type>;
    using value_type = super::value_type;
    using key_type = super::key_type;
    using mapped_type = super::mapped_type;
    using const_iterator = super::const_iterator;

    // All the same constructors as the super class.
    using super::super;
    // But initializer lists require a distinct constructor.
    enum_map(std::initializer_list<value_type> list) : super(list) {}

    using super::find;
    // Lookup by enum value. Return iterator or end().
    const_iterator find(mapped_type value) const {
        return std::ranges::find_if(*this, [value](auto& pair)
        {
            return pair.second == value;
        });
    }

    using super::at;
    // Lookup by enum value. Return reference to key or throw 
    key_type const& at(mapped_type value) const {
        if (auto iter = find(value); iter != this->end())
            return iter->first;
        else
            throw std::out_of_range("enum_map::at()");
    }
};
