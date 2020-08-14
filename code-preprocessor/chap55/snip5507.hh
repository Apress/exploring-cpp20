/** @file snip5507.hh */
/** Code Snippet 55-7 */
template<class T>
concept any_integral = std::numeric_limits<T>::is_integer;
