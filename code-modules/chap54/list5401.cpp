#include <iostream>
#include <string>
#include "list5401.hh"

template<class T, class U>
pair<T, U>::pair(T const& first, U const& second) : first(first), second(second)
{}

int main()
{
   pair<int, std::string> p{ 1, "test" };
   std::cout << p.first << ' ' << p.second << '\n';
}
