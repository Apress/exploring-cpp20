/** @file list5402.hh */
/** Listing 54-2. Specializing pair<> for Two void Arguments */
template<>
struct pair<void, void>
{
   using first_type = void;
   using second_type = void;
   pair(pair const&) = default;
   pair() = default;
   pair& operator=(pair const&) = default;
};
