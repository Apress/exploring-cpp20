/** @file snip4710.hh */
/** Code Snippet 47-10 */
auto data{ std::ranges::views::iota(0, 10) }; // [0, 10)

auto demo1 = data | std::ranges::views::drop(2) | std::ranges::views::take(5);
auto demo2 = std::ranges::views::drop(data, 2) | std::ranges::views::take(5);
auto demo3 = std::ranges::views::take(std::ranges::views::drop(data, 2), 5);
auto demo4 = std::ranges::views::take(5)(std::ranges::views::drop(2)(data));
