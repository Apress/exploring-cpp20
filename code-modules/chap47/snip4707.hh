/** @file snip4707.hh */
/** Code Snippet 47-7 */
std::vector<std::string> strings{"string", "one", "two", "testing" };
auto sizes = strings 
    | std::ranges::views::transform([](auto&& str) { return str.size(); })
    | std::ranges::views::filter([](auto size) { return size > 3; });
