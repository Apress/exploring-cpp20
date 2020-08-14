/** @file snip4602.hh */
/** Code Snippet 46-2 */
std::vector<int> data{ 1, 2, 3, 4, 5 };
auto iter{ data.begin() };
std::cout << "4 == " << *std::next(iter, 3) << '\n';
