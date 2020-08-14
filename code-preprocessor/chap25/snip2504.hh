/** @file snip2504.hh */
/** Code Snippet 25-4 */
data.resize(10);      // if the old size < 10, use default of 0 for new elements
data.resize(20, -42); // if the old size < 20, use -42 for new elements
