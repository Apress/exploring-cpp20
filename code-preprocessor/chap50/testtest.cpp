#include <stdexcept>
#include "test.hpp"

int main()
{
	TEST(false);
	TEST(true);
	TEST_EQUAL(1, 2);
	TEST_EQUAL(1, 1);
	TEST((throw std::runtime_error("oops"), true));
	test_exit();
}
