#include <iostream>
#include <numeric>
#include <stdexcept>
class rational {
public:
  class zero_denominator : public std::logic_error {
  public:
    using std::logic_error::logic_error;
  };
  rational() : numerator_{}, denominator_{} {
    reduce();
  }
private:
  void reduce();
  int numerator_;
  int denominator_;
};

#include "list4808.hh"
int main() {
rational r{};
}
