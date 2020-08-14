/** @file list5403.hh */
/** Listing 54-3. Specializing pair for One void Argument */
template<class U>
struct pair<void, U>
{
   typedef void first_type;
   typedef U second_type;
   U second;
   pair() = default;
   pair(pair const&) = default;
   pair(U const& second) : second{second} {}
   template<class U2>
   pair(pair<void, U2> const& other);
};
