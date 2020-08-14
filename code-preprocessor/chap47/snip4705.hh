/** @file snip4705.hh */
/** Code Snippet 47-5 */
std::map<std::string, int> barn{ {"horse", 3}, {"dog", 4}, {"cat", 0} };
for (auto const& animal : barn | std::ranges::views::keys)    std::cout << animal << '\n';
