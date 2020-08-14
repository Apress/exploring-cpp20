#include <iostream>
#include "list5201.hh"
#include "list5202.hh"

int main()
{
point<int> p{1,2};
p.move_by(1,2);
std::cout << p.x() << ',' << p.y() << '\n';
}
