/** @file list5602.hh */
/** Listing 56-2. Defining the fixed Class Template in the numeric Namespace */
export module fixed;
namespace numeric
{
  export template<class T, int N>
  class fixed
  {
//     ... copied from Exploration 54...

#include "list5602.inc0"
  };

  export template<class T, int N>
  bool operator==(fixed<T,N> const& a, fixed<T,N> const& b);

  export template<class T, int N>
  fixed<T,N> operator+(fixed<T,N> const& a, fixed<T,N> const& b);
  // and so on...
} // namespace numeric
