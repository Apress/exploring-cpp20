/** @file snip6808.hh */
/** Code Snippet 68-8 */
struct demo {
  color okay  : 3; // big enough
  color small : 2; // oops, not enough bits, but valid C++
};
