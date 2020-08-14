/** @file snip7001.hh */
/** Code Snippet 70-1 */
template<class T>
typename std::remove_reference<T>::type&& move(T&& t) noexcept
{
   return static_cast<typename std::remove_reference<T>::type&&>(t);
}
