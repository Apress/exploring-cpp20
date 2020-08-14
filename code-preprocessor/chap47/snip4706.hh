/** @file snip4706.hh */
/** Code Snippet 47-6 */
std::map<std::string, int> barn{ {"horse", 3}, {"dog", 4}, {"cat", 0} };
auto animals{ barn | std::ranges::views::reverse | std::ranges::views::keys };
for (auto const& animal : animals)    std::cout << animal << '\n';
