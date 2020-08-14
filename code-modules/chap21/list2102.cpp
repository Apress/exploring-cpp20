/** @file list2102.cpp */
/** Listing 21-2. Pass Parameters by Reference */
import <algorithm>;
import <iostream>;
import <iterator>;
import <vector>;

void modify(int& x)
{
  x = 10;
}

int triple(int x)
{
  return 3 * x;
}

void print_vector(std::vector<int>& v)
{
  std::cout << "{ ";
  std::ranges::copy(v, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "}\n";
}

void add(std::vector<int>& v, int a)
{
  for (auto iter{v.begin()}, end{v.end()}; iter != end; ++iter)
    *iter = *iter + a;
}

int main()
{
  int a{42};
  modify(a);
  std::cout << "a=" << a << '\n';

  int b{triple(14)};
  std::cout << "b=" << b << '\n';

  std::vector<int> data{ 10, 20, 30, 40 };

  print_vector(data);
  add(data, 42);
  print_vector(data);
}
