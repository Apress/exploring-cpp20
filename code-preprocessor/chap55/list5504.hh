/** @file list5504.hh */
/** Listing 55-4. Constraining the size Function */
template<class T>
auto size(T const& container)
   requires
      requires(T container) {
         container.size();
         typename T::size_type;
         { container.size() } -> std::same_as<typename T::size_type>;
      }
{
   return container.size();
}
