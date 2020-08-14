/** @file list3006.hh */
/** Listing 30-6. Modifying the reduce Member Function to Accept a Negative Denominator */
  /// Reduces the numerator and denominator by their GCD.
  void reduce()
  {
    assert(denominator != 0);
    if (denominator < 0)
    {
      denominator = -denominator;
      numerator = -numerator;
    }
    int div{std::gcd(numerator, denominator)};
    numerator = numerator / div;
    denominator = denominator / div;
  }
