#include "rational.hpp"
#include "list3106.hh"
#include "test.hpp"
int main() {
    rational a{ 1, 2 };
    rational b{ 1 };
    rational c{ -1, 2 };

    TEST(a + a == b);
    TEST(-a == c);
    TEST(a == -(-a));
}
