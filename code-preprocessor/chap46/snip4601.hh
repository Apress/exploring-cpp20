/** @file snip4601.hh */
/** Code Snippet 46-1 */
std::vector<std::string> lines(2, "hello");
std::string first{*lines.begin()};   // dereference the first item
std::size_t size{lines.begin()->size()};     // dereference and call a member function
