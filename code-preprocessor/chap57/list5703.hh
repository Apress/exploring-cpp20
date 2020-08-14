/** @file list5703.hh */
/** Listing 57-3. Erasing Elements from a Sequence Container */
template<class Container>
void erase_unsorted(Container& cont)
{
  auto prev{cont.end()};
  auto next{cont.begin()};
  while (next != cont.end())
  {
    // invariant: std::is_sorted(cont.begin(), prev);
    if (prev != cont.end() and *next < *prev)
      next = cont.erase(next);
    else
    {
      prev = next;
      ++next;
    }
  }
}
