/** @file snip7209.hh */
/** Code Snippet 72-9 */
template<class T> class rational {
public:
  rational(T const& num = T{0}, T const& den = T{1})
  : numerator_{num}, denominator_{den}
  {
    reduce();
  }
//   ...omitted for brevity...

#include "snip7209.inc0"
};
