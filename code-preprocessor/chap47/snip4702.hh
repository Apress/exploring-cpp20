/** @file snip4702.hh */
/** Code Snippet 47-2 */
std::string string{"string"};
auto ring = string | std::ranges::views::drop(2);
