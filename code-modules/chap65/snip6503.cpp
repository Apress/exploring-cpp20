#include <iostream>
#include <memory>

struct rational
{
rational(int, int) {}
int numerator() const { return 42; }
};
int socket=0;

void sendto(int, void const*, std::size_t, int, void const*, int)
{}

int main() {
#include "snip6503.hh"
}
