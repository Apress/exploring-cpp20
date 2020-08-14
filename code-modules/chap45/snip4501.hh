/** @file snip4501.hh */
/** Code Snippet 45-1 */
std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout));
std::ranges::copy(data, std::ostream_iterator<int>(std::cout));
