#include <iostream>
#include <numeric>
#include <stdexcept>

template<class T>
class rational
{
public:
  using value_type = T;
  rational() : rational{0} {}
  rational(value_type num) : numerator_{num}, denominator_{1} {}
  rational(value_type num, value_type den);

  template<class U>
  rational(rational<U> const&);

  void assign(value_type num, value_type den);

  #include "snip5207.hh"

  rational const& operator +=(rational const& rhs);
  rational const& operator -=(rational const& rhs);
  rational const& operator *=(rational const& rhs);
  rational const& operator /=(rational const& rhs);

  template<class U>
  U convert()
  const
  {
    return static_cast<U>(numerator()) / static_cast<U>(denominator());
  }

  value_type const& numerator() const { return numerator_; }
  value_type const& denominator() const { return denominator_; }
private:
  void reduce();
  value_type numerator_;
  value_type denominator_;
};

template<class T>
rational<T>::rational(value_type num, value_type den)
: numerator_{num}, denominator_{den}
{
  reduce();
}

template<class T>
void rational<T>::assign(value_type num, value_type den)
{
  numerator_ = num;
  denominator_ = den;
  reduce();
}

template<class T>
bool operator==(rational<T> const& a, rational<T> const& b)
{
  return a.numerator() == b.numerator() and
         a.denominator() == b.denominator();
}

template<class T>
inline bool operator!=(rational<T> const& a, rational<T> const& b)
{
  return not (a == b);
}

template<class T>
  void rational<T>::reduce()
  {
    if (denominator() == value_type{}) throw std::logic_error("divide by zero in rational");
    if (denominator() < value_type{})
    {
      denominator_ = -denominator();
      numerator_ = -numerator();
    }
    int div{std::gcd(numerator(), denominator())};
    numerator_ = numerator() / div;
    denominator_ = denominator() / div;
  }

template<class T>
std::ostream& operator<<(std::ostream& stream, rational<T> const& r)
{
  std::cout << r.numerator() << '/' << r.denominator();
  return stream;
}



#include "list5208.hh"
#include "list5209.hh"

int main()
{
  rational<int> r1{16,4};
  rational<long> r2{r1};

  r1 = r2;
  std::cout << r1 << '\n';
}
