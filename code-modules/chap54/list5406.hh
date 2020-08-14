/** @file list5406.hh */
/** Listing 54-6. Changing fixed from a Class to a Class Template */
template<class T, int N>
class fixed
{
public:
    using value_type = T;
    static constexpr int places{N};
    static constexpr int places10{ipower(10, N)};
    fixed();
    fixed(T const& integer, T const& fraction);
    fixed& operator=(fixed const& rhs);
    fixed& operator+=(fixed const& rhs);
    fixed& operator*=(fixed const& rhs);
//     ... and so on...

#include "list5406.inc0"
private:
    T value_; // scaled to N decimal places
};

template<class T, int N>
fixed<T, N>::fixed(value_type const& integer, value_type const& fraction)
: value_(integer * places10 + fraction)
{}

template<class T1, int N1, class T2, int N2>
bool operator==(fixed<T1,N1> const& a, fixed<T2,N2> const& b);

// ... and so on...

#include "list5406.inc1"
