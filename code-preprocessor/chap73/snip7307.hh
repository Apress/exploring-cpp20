/** @file snip7307.hh */
/** Code Snippet 73-7 */
using iterator = choice<ITERATOR_TYPE,
    pedantic_iterator, safe_iterator, fast_iterator>::type;
