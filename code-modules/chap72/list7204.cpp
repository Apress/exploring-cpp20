/** @file list7204.cpp */
/** Listing 72-4. Ranking Functions for Overload Resolution */
import <iostream>;
import <string>;

void print(std::string_view str) { std::cout << str; }
void print(int x)                { std::cout << "int: " << x; }
void print(double x)             { std::cout << "double: " << x; }

class base {
public:
  void print(std::string_view str) const { ::print(str); ::print("\n"); }
  void print(std::string_view s1, std::string_view s2)
  {
    print(s1); print(s2);
  }
};

class convert : public base {
public:
  convert()              { print("convert()"); }
  convert(double)        { print("convert(double)"); }
  operator int() const   { print("convert::operator int()"); return 42; }
  operator float() const { print("convert::operator float()"); return 3.14159f; }
};

class demo : public base {
public:
  demo(int)      { print("demo(int)"); }
  demo(long)     { print("demo(long)"); }
  demo(convert)  { print("demo(convert)"); }
  demo(int, int) { print("demo(int, int)"); }
};

class other {
public:
  other()        { std::cout << "other::other()\n"; }
  other(int,int) { std::cout << "other::other(int, int)\n"; }
  operator convert() const
  {
    std::cout << "other::operator convert()\n"; return convert();
  }
};

int operator+(demo const&, demo const&)
{
  print("operator+(demo,demo)\n"); return 42;
}

int operator+(int, demo const&) { print("operator+(int,demo)\n"); return 42; }

int main()
{
  other x{};
  demo d{x};
  3L + d;
  short s{2};
  d + s;
}
