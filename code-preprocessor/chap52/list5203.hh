/** @file list5203.hh */
/** Listing 52-3. The rational Class Template */
template<class T>
class rational
{
public:
  using value_type = T;
  rational() : rational{0} {}
  rational(value_type num) : numerator_{num}, denominator_{1} {}
  rational(value_type num, value_type den);

  void assign(value_type num, value_type den);

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
