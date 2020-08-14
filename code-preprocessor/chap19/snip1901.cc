#include <iostream>
#include <locale>
int main()
{
	std::cout << std::boolalpha;
	std::cout << std::isupper('A', std::locale{"en_US.latin1"}) << '\n';
	std::cout << std::islower('A', std::locale{"en_US.latin1"}) << '\n';
	std::cout << std::isupper('Æ', std::locale{"en_US.latin1"}) << '\n';
	std::cout << std::islower('Æ', std::locale{"en_US.latin1"}) << '\n';
	std::cout << std::islower('½', std::locale{"en_US.latin1"}) << '\n';
	std::cout << std::isupper('½', std::locale{"en_US.latin1"}) << '\n';
}
