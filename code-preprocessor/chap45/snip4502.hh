/** @file snip4502.hh */
/** Code Snippet 45-2 */
auto iter{std::lower_bound(data.begin(), data.end(), 42)};
std::cout << "Index of 42 is " << std::distance(data.begin(), iter) << '\n';
