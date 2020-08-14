/** @file list2702.cpp */
/** Listing 27-2. Discovering the Attributes of a Floating-Point Type */
import <cmath>;
import <iostream>;
import <limits>;
import <locale>;

int main()
{
  std::cout.imbue(std::locale{""});
  std::cout << std::boolalpha;
  // Change float to double or long double to learn about those types.
  using T = float;
  std::cout << "min=" << std::numeric_limits<T>::min() << '\n'
       << "max=" << std::numeric_limits<T>::max() << '\n'
       << "IEC 60559? " << std::numeric_limits<T>::is_iec559 << '\n'
       << "max exponent=" << std::numeric_limits<T>::max_exponent << '\n'
       << "min exponent=" << std::numeric_limits<T>::min_exponent << '\n'
       << "mantissa places=" << std::numeric_limits<T>::digits << '\n'
       << "radix=" << std::numeric_limits<T>::radix << '\n'
       << "has infinity? " << std::numeric_limits<T>::has_infinity << '\n'
       << "has quiet NaN? " << std::numeric_limits<T>::has_quiet_NaN << '\n'
       << "has signaling NaN? " << std::numeric_limits<T>::has_signaling_NaN << '\n';

  if (std::numeric_limits<T>::has_infinity)
  {
    T zero{0};
    T one{1};
    T inf{std::numeric_limits<T>::infinity()};
    if (std::isinf(one/zero))
      std::cout << "1.0/0.0 = infinity\n";
    if (inf + inf == inf)
      std::cout << "infinity + infinity = infinity\n";
  }
  if (std::numeric_limits<T>::has_quiet_NaN)
  {
    // There's no guarantee that your environment produces quiet NaNs for
    // these illegal arithmetic operations. It's possible that your compiler's
    // default is to produce signaling NaNs, or to terminate the program
    // in some other way.
    T zero{};
    T inf{std::numeric_limits<T>::infinity()};
    std::cout << "zero/zero = " << zero/zero << '\n';
    std::cout << "inf/inf = " << inf/inf << '\n';
  }
}
