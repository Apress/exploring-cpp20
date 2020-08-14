#include <iostream>
#include "stats.hpp"

int main() {
  std::cout << "Bogus Metabolic Indicator\n";
  vital_stats stats;
  int count{0};
  while (stats.read(std::cin, count))
  {
	static constexpr int threshold{ 30 };
	++count;
    stats.print(std::cout, threshold);
  }
}
