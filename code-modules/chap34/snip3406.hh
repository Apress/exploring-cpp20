/** @file snip3406.hh */
/** Code Snippet 34-6 */
struct dont_copy
{
   dont_copy(dont_copy const&) = delete;
};
