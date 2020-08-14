/** @file snip3404.hh */
/** Code Snippet 34-4 */
struct point {
  point() {} // x_ is initialized to 0, and y_ is uninitialized
  double x_{};
  double y_;
};
