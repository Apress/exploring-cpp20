/** @file list3001.hh */
/** Listing 30-1. Defining a Custom rational Type */
/// Represent a rational number.
struct rational
{
  int numerator;     ///< numerator gets the sign of the rational value
  int denominator;   ///< denominator is always positive
};
