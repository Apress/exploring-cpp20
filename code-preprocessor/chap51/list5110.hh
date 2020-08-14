/** @file list5110.hh */
/** Listing 51-10. Another Way to Implement the copy Algorithm */
auto copy(auto range, auto output)
{
  for (auto const& item : range)
    *output++ = item;
  return output;
}
