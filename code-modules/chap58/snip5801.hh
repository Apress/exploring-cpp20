/** @file snip5801.hh */
/** Code Snippet 58-1 */
std::cin.imbue(std::locale::classic()); // standard input uses the classic locale
std::cout.imbue(std::locale{""});       // imbue with the user's default locale
