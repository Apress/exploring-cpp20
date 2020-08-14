/** @file snip1104.hh */
/** Code Snippet 11-4 */
auto temporary{ *left };
*left = *right;
*right = temporary;
