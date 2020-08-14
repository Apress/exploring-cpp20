/** @file snip2607.hh */
/** Code Snippet 26-7 */
long big{2147483640};
short small{7};
std::cout << big + small; // promote small to type int; then convert it to long;
                          // the sum has type long
