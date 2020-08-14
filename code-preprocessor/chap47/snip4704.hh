/** @file snip4704.hh */
/** Code Snippet 47-4 */
std::vector<std::string> words{ "this", " ", "is an", " ", "example" };
auto sentence = words | std::ranges::views::join;
