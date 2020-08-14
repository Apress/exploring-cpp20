/** @file list5502.hh */
/** Listing 55-2. Constraining the copy Function’s Arguments */
template<class Input, class Output>
Output copy(Input input, Output output)
   requires
       std::ranges::input_range<Input> and
       std::output_iterator<Output, std::ranges::range_value_t<Input>>
{
   for (auto const& item : input)
       *output++ = item;
   return output;
}
