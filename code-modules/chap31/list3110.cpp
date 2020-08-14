#include "rational.hpp"
#include "list3110.hh"
int main() {
	rational pi{355, 113};
	rational pi2{ 2 * pi };
	rational pi4{ 4 * pi };
	std::cout << pi2.numerator << '/' << pi2.denominator << '\n';
	std::cout << pi4.numerator << '/' << pi4.denominator << '\n';
}
