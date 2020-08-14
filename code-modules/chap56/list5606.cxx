/** @file list5606.cxx */
/** Listing 56-6. Examples of using Directives */
import <iostream>;

void print(int i)
{
  std::cout << "int: " << i << '\n';
}

namespace labeled
{
  void print(double d)
  {
    std::cout << "double: " << d << '\n';
  }
}

namespace simple
{
  void print(int i)
  {
    std::cout << i << '\n';
  }
  void print(double d)
  {
    std::cout << d << '\n';
  }
}

void test_simple()
{
  using namespace simple;
  print(42);                // ???
  print(3.14159);           // finds simple::print(double)
}

void test_labeled()
{
  using namespace labeled;
  print(42);                // find ::print(int)
  print(3.14159);           // finds labeled::print(double)
}

int main()
{
  test_simple();
  test_labeled();
}
