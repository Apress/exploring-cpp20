/** @file list5604.hh */
/** Listing 56-4. Alternative Style of Function Declaration */
template<class T, int N>
auto numeric::operator+(fixed<T, N> const& a, fixed<T, N> const& b) -> fixed<T, N>
{
  fixed<T, N> result{a};
  result += b;
  return result;
}
