/** @file list5408.hh */
/** Listing 54-8. Specializing fixed for N == 0 */
template<class T>
class fixed<T, 0>
{
public:
    using value_type = T;
    static constexpr T places{0};
    static constexpr T places10{1};
    fixed() : value_{} {}
    fixed(T const& integer, T const&);
    fixed& operator=(fixed const& rhs) { value_ = rhs; }
    fixed& operator+=(fixed const& rhs) { value_ += rhs; }
    fixed& operator*=(fixed const& rhs) { value_ *= rhs; }
//     ... and so on...

#include "list5408.inc0"
private:
    T value_; // no need for scaling
};

template<class T>
fixed<T, 0>::fixed(value_type const& integer, value_type const&)
: value_(integer)
{}
