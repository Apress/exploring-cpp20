/** @file list5601.hh */
/** Listing 56-1. Defining the rational Class Template in the numeric Namespace */
namespace numeric
{
  template<class T>
  class rational
  {
//     ... you know what goes here...

#include "list5601.inc0"
  };
  template<class T>
  bool operator==(rational<T> const& a, rational<T> const& b);
  template<class T>
  rational<T> operator+(rational<T> const& a, rational<T> const& b);
//   ... and so on...

#include "list5601.inc1"
} // namespace numeric
