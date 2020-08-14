/** @file snip5205.hh */
/** Code Snippet 52-5 */
template<class T> bool operator==(rational<T> const& lhs, T rhs);
template<class T> bool operator==(T lhs, rational<T> const& rhs);
template<class T> bool operator!=(rational<T> const&  lhs, T rhs);
template<class T> bool operator!=(T lhs, rational<T> const& rhs);
