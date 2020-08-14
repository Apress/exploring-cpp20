/** @file snip4701.hh */
/** Code Snippet 47-1 */
std::vector<int> data{ 1, 2, 3, 4, 5 };
std::ranges::subrange sub{ std::ranges::begin(data), std::ranges::end(data) };
std::ranges::copy(sub.next(2), std::ostream_iterator<int>(std::cout, "\n"));
