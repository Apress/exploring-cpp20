/** @file list5302.hh */
/** Listing 53-2. Specializing rational<void> */
import rational;

template<>
class rational<void>
{
public:
  using value_type = void;
  rational() {}

  int numerator() const { return 0; }
  int denominator() const { return 1; }
};
