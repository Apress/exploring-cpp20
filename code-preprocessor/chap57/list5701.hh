/** @file list5701.hh */
/** Listing 57-1. Specializing the hash Template for the rational Type */
#include <functional>
#include "rational.hpp"
namespace std {

template<class T>
class hash<rational<T>>
{
public:
  std::size_t operator()(rational<T> const& r)
  const
  {
    return hasher_(r.numerator() * r.denominator());
  }
private:
  std::hash<T> hasher_;
};
} // end of std
