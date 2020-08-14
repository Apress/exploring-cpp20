/** @file snip4709.hh */
/** Code Snippet 47-9 */
std::map<std::string, int> barn{ {"horse", 3}, {"dog", 4}, {"cat", 0} };
int total{0};
for (auto count : barn | std::ranges::views::values)    total += count;
