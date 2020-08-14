/** @file list5404.hh */
/** Listing 54-4. Specializing pair for the Other void Argument */
template<class T>
struct pair<T, void>
{
   typedef T first_type;
   typedef void second_type;
   T first;
   pair() = default;
   pair(pair const&) = default;
   pair(T const& first) : first{first} {}
   template<class T2>
   pair(pair<T2, void> const& other);
};
