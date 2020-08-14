/** @file snip3601.hh */
/** Code Snippet 36-1 */
point(double a, double b, bool is_polar)
{
  if (is_polar)
    move_polar(a, b);
  else
    move_cartesian(a, b);
}
