#include <type_traits>
#include "list7308.hh"
#include "list7307.hpp"

int main() {
	static_assert(std::is_same<int, promote<bool>::type>::value);
	static_assert(std::is_same<int, promote<char>::type>::value);
	static_assert(std::is_same<int, promote<short>::type>::value);
	static_assert(std::is_same<int, promote<int>::type>::value);
	static_assert(std::is_same<long, promote<long>::type>::value);
}
