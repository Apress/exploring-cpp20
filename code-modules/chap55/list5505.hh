/** @file list5505.hh */
/** Listing 55-5. Constraining the size Function */
template<class T>
requires
   requires(T container) {
      container.size();
      typename T::size_type;
      { container.size() } -> std::same_as<typename T::size_type>;
   }
auto size(T const& container)
{
   return container.size();
}
