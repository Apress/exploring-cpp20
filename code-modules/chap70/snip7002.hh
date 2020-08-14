/** @file snip7002.hh */
/** Code Snippet 70-2 */
template<class T>
concept integral = std::is_integral<T>::value;
