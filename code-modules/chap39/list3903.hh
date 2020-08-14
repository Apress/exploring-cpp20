/** @file list3903.hh */
/** Listing 39-3. Output Operator for Class work */
std::ostream& operator<<(std::ostream& out, work const& w)
{
  w.print(out);
  return out;
}
