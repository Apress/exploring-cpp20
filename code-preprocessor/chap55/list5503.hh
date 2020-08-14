/** @file list5503.hh */
/** Listing 55-3. Constraining a Multiplication Operator */
template<class T, class U>
U operator*(rational<T> const& lhs, U const& rhs)
   requires
      requires(T lhs, U rhs) {
         (lhs * rhs) / lhs;
      }
{
   return lhs.numerator() * rhs / lhs.denominator();
}
