/** @file list4406.hpp */
/** Listing 44-6. The sequence Module */

// export module sequence;
/// Generate a sequence of integers.
/*export*/ class sequence
{
public:
  /// Construct the functor.
  /// @param start the first value the generator returns
  /// @param step increment the value by this much for each call
  inline sequence(int start, int step ) : value_{start}, step_{step} {}
  inline sequence(int start) : sequence{start, 1} {}
  inline sequence() : sequence{0} {}

  /// Return the current value in the sequence, and increment the value.
  int operator()()
  {
    int result(value_);
    value_ = value_ + step_;
    return result;
  }
private:
  int value_;
  int const step_;
};
