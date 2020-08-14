/** @file snip2703.hh */
/** Code Snippet 27-3 */
double const pi{3.141592653589793238L};
std::cout.precision(12);
std::cout << pi << '\n';
std::cout << std::setprecision(4) << pi << '\n';
std::cout << std::format("{0:.12}\n{0:.4}\n", pi);
