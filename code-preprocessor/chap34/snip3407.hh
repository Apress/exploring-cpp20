/** @file snip3407.hh */
/** Code Snippet 34-7 */
struct point
{
  point() = default;
  point(point const&) = default;
  int x, y;
};
