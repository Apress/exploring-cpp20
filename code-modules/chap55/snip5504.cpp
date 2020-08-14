#include <iostream>
#include <iterator>
#include <vector>
using iterator = std::vector<int>;
using const_iterator = iterator;
#include "snip5504.hh"

template<class I>
iterator insert(const_iterator v, I first, I last)
    requires std::input_iterator<I>
{
    v.insert(v.end(), first, last);
    return v;
}

int main()
{
  std::vector<int> v;
  std::vector<int> data{ 1, 2, 3, 4 };
  v = insert(std::move(v), data.begin(), data.end());
  std::cout << v.size() << '\n';
}
