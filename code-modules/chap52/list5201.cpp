#include <iostream>
#include "list5201.hh"
int main()
{
point<int> p{1,2};
p.move_to(2,1);
std::cout << p.x() << ',' << p.y() << '\n';
}
