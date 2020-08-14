/** @file list4505.hpp */
/** Listing 45-5. Generating Random Integers */
// export module randomint;

#include <algorithm>
#include <random>

/// Generate uniformly distributed random integers in a range.
/*export*/ class randomint
{
public:
  using result_type = std::default_random_engine::result_type;

  /// Construct a random-number generator to produce numbers in the range [`low`, `high`].
  /// If @p low > @p high the values are reversed.
  randomint(result_type low, result_type high)
  : prng_{},
    distribution_{std::min(low, high), std::max(low, high)}
  {}

  /// Generate the next random number generator.
  result_type operator()()
  {
     return distribution_(prng_);
  }

private:
  // implementation-defined pseudo-random-number generator
  std::default_random_engine prng_;
  // Map random numbers to a uniform distribution.
  std::uniform_int_distribution<result_type> distribution_;
};
