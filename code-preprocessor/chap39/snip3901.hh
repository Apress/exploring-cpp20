/** @file snip3901.hh */
/** Code Snippet 39-1 */
std::ostream& operator<<(std::ostream& out, work w)
{
  w.print(out);
  return out;
}
