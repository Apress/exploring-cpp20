/** @file list5401.hh */
/** Listing 54-1. The pair Class Template */
template<class T, class U>
struct pair
{
   using first_type = T;
   using second_type = U;
   T first;
   U second;
   pair();
   pair(T const& first, U const& second);
   template<class T2, class U2>
   pair(pair<T2, U2> const& other);
};
