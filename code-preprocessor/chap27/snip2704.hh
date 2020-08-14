/** @file snip2704.hh */
/** Code Snippet 27-4 */
std::cout << std::scientific << large_number << '\n';
std::cout << std::fixed << small_number << '\n';
std::cout.unsetf(std::ios_base::floatfield);
std::cout << number_in_general_format << '\n';
std::cout << std::format("{:e}\n{:f}\n{}\n",    large_number, small_number, number_in_general_format);
