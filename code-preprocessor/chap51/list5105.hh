/** @file list5105.hh */
/** Listing 51-5. One Way to Implement the copy Algorithm */
template<class InputRange, class OutputIterator>
OutputIterator copy(InputRange range, OutputIterator output)
{
  for (auto const& item : range)
    *output++ = item;
  return output;
}
