/** @file list4401.hpp */
/** Listing 44-1. Rewriting generate_id to Use the Function Call Operator */
// export module generate_id;
/// Class for generating a unique ID number.
/*export*/ class generate_id
{
public:
  generate_id() : counter_{0} {}
  long operator()();
private:
  short counter_;
  static short prefix_;
  static short constexpr max_counter_{32767};
};
