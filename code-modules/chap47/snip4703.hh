/** @file snip4703.hh */
/** Code Snippet 47-3 */
auto positives = data 
    | std::ranges::views::filter([](auto value) { return value > 0; });
