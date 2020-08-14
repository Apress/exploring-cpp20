/** @file list6404.cpp */
/** Listing 64-4. Examining Expression Categories */
#include <iostream>
#include <string>
#include <utility>

void print(std::string&& move)
{
   std::cout << "move: " << std::move(move) << '\n';
}

void print(std::string const& copy)
{
   std::cout << "copy: " << copy << '\n';
}

int main()
{
   std::string a{"a"}, b{"b"}, c{"c"};

  print(a);
  print(a + b);
  print(a + b + c);
  print(std::move(a + b));
  print(a + std::move(b));
  print(std::move(a));
} 
