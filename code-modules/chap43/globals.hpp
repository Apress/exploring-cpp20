/** @file globals.hpp */
/** Listing 43-5. Simple Header for Global Constants */
#ifndef GLOBALS_HPP_
#define GLOBALS_HPP_

#include <string_view>

constexpr std::string_view program_name{ "The Ultimate Program" };
constexpr std::string_view program_version{ "1.0" };

extern const std::string_view program_credits;


#endif
