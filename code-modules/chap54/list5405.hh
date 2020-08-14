/** @file list5405.hh */
/** Listing 54-5. Partially Specializing numeric_limits for rational */
namespace std {
template<class T>
class numeric_limits<rational<T>>
{
public:
  static constexpr bool is_specialized{true};
  static constexpr rational<T> min() noexcept {
    return rational<T>(numeric_limits<T>::min());
  }
  static constexpr rational<T> max() noexcept {
    return rational<T>(numeric_limits<T>::max());
  }
  static rational<T> lowest() noexcept { return -max(); }
  static constexpr int digits{ 2 * numeric_limits<T>::digits };
  static constexpr int digits10{ numeric_limits<T>::digits10 };
  static constexpr int max_digits10{ numeric_limits<T>::max_digits10 };
  static constexpr bool is_signed{ numeric_limits<T>::is_signed };
  static constexpr bool is_integer{ false };
  static constexpr bool is_exact{ true };
  static constexpr int radix{ 2 };
  static constexpr bool is_bounded{ numeric_limits<T>::is_bounded };
  static constexpr bool is_modulo{ false };
  static constexpr bool traps{ std::numeric_limits<T>::traps };
//   ... omitted for brevity

#include "list5405.inc0"
};
} // namespace std
