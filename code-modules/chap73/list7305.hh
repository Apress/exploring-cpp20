/** @file list7305.hh */
/** Listing 73-5. Implementing the is_same Metafunction */
template<class T, class U>
struct is_same : std::false_type {};

template<class T>
struct is_same<T, T> : std::true_type {};

