/** @file snip4708.hh */
/** Code Snippet 47-8 */
std::string string{"string"};
std::ranges::copy(string | std::ranges::views::take(3),
     std::ostreambuf_iterator(std::cout));
