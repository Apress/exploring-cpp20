/** @file list6001.hh */
/** Listing 60-1. Module That Declares a Trivial Debugging Function */
export module debug;
import <string_view>;

/** @brief Write a debug message to the file @c "debug.txt"
 * @param msg The message to write
 */
export void debug(std::string_view msg);
