/** @file list7310.hh */
/** Listing 73-10. Implementing an Integer-Keyed Type Choice */
#include <type_traits>

// forward declaration
template<std::size_t, class...>
struct choice;

// Default: subtract one, drop the head of the list, and recurse.
template<std::size_t N, class T, class... Types>
struct choice_split {
    using type = choice<N-1, Types...>::type;
}; 

// Index 0: pick the first type in the list.
template<class T, class... Ts>
struct choice_split<0, T, Ts...> {
    using type = T;
};

// Define type member as the N-th type in Types.
template<std::size_t N, class... Types>
struct choice {
    using type = choice_split<N, Types...>::type;
};

// N is out of bounds
template<std::size_t N>
struct choice<N> {};

// Tests

static_assert(std::is_same<int,
  typename choice<0, int, long, char>::type>::value, "error in choice<0>");
static_assert(std::is_same<long,
  typename choice<1, int, long, char>::type>::value, "error in choice<1>");
static_assert(std::is_same<char,
  typename choice<2, int, long, char>::type>::value, "error in choice<2>");
