/** @file list4903.hh */
/** Listing 49-3. Searching for a Matching Sub-range Using Iterators */
auto search(auto first1, auto last1, auto first2, auto last2)
{
  // s1 is the size of the untested portion of the first range
  // s2 is the size of the second range
  // End the search when s2 > s1 because a match is impossible if the
  // remaining portion of the search range is smaller than the test range.
  // Each iteration of the outer loop shrinks the search range by one,
  // and advances the first1 iterator. The inner loop searches
  // for a match starting at first1.
  for (auto s1{last1-first1}, s2{last2-first2}; s2 <= s1; --s1, ++first1)
  {
    // Is there a match starting at first1?
    auto f2{first2};
    for (auto f1{first1};
         f1 != last1 and f2 != last2 and *f1 == *f2;
         ++f1, ++f2)
     {
        // The subsequence matches so far, so keep checking.
        // All the work is done in the loop header, so the body is empty.
     }
     if (f2 == last2)
       return first1;     // match starts at first1
  }
  // no match
  return last1;
}
