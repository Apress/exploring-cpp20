/** @file list5209.hh */
/** Listing 52-9. Defining a Member Constructor Template */
template<class T>
template<class U>
rational<T>::rational(rational<U> const& copy)
: numerator_{copy.numerator()}, denominator_{copy.denominator()}
{}
