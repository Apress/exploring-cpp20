/** @file snip5504.hh */
/** Code Snippet 55-4 */
template<class InputIterator>
iterator insert(const_iterator pos, InputIterator first, InputIterator last)
    requires std::input_iterator<InputIterator>;
