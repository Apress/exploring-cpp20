/** @file snip7003.hh */
/** Code Snippet 70-3 */
template<class T>
concept signed_integral = integral<T> and std::is_signed<T>::value;
