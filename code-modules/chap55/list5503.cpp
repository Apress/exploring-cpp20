#include <iostream>

template<class T>
class rational
{
public:
   rational(T n, T d) : num_{n}, den_{d} {}
   T numerator() const { return num_; }
   T denominator() const { return den_; }
private:
   T num_;
   T den_;
};

#include "list5503.hh"
int main() {
   rational<int> pi{355,113};
   std::cout << pi * 2.0 << '\n';
}
