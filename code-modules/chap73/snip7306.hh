/** @file snip7306.hh */
/** Code Snippet 73-6 */
template<class... Ts>
struct Size { constexpr static std::size_t value = sizeof...(Ts); };
static_assert(Size<int, char, long>::value == 3);
