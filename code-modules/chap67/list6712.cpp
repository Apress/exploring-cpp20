/** @file list6712.cpp */
/** Listing 67-12. Fixing the Second Mystery Program */
import <algorithm>;
import <iostream>;
import <iterator>;
import <vector>;

/** Return the index of a value in a range.
 * Look for the first occurrence of @p value in the range
 * [<tt>first</tt>, <tt>last</tt>), and return the zero-based
 * index or -1 if @p value is not found.
 * @param first The start of the range to search
 * @param last One past the end of the range to search
 * @param value The value to search for
 * @return [0, size), such that size == last-first, or -1
 */
template<class Range>
    requires std::ranges::forward_range<Range>
std::ranges::range_difference_t<Range>
index_of(Range const& range, std::ranges::range_value_t<Range> const& value)
{
   auto iter{std::ranges::find(range, value)};
   if (iter == std::ranges::end(range))
      return -1;
   else
      return std::distance(std::ranges::begin(range), iter);
}

/** Determine whether the first occurrence of a value in a container is
 * in the last position in the container.
 * @param container Any standard container
 * @param value The value to search for.
 * @return true if @p value is at the last position,
 *         or false if @p value is not found or at any other position.
 */
template<class T>
bool is_last(T const& container, typename T::value_type const& value)
{
    auto index{ index_of(container, value) };
    decltype(index) last{ container.size() - 1 };
    return index == last;
}

int main()
{
   std::vector<int> data{};
   if (is_last(data, 10))
      std::cout << "10 is the last item in data\n";
}
