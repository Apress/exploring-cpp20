#include <iostream>
#include <filesystem>
#include "list6002.hh"
int main() {
  std::filesystem::remove("debug.txt");
  debug("This is a test");

  std::ifstream f("debug.txt");
  std::string line;
  while(std::getline(f, line)) {
    std::cout << line << '\n';
  }
}
