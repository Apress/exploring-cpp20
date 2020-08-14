/** @file list4405.cpp */
/** Listing 44-5. Another Program for Generating Successive Integers */
import <algorithm>;
import <iostream>;
import <iterator>;
import <vector>;

import sequence;

int main()
{
  int size{};
  std::cout << "How many integers do you want? ";
  std::cin >> size;
  int first{};
  std::cout << "What is the first integer? ";
  std::cin >> first;
  int step{};
  std::cout << "What is the interval between successive integers? ";
  std::cin >> step;
 
  std::vector<int> data(size);
  // Generate the integers to fill the vector.
  std::ranges::generate(data, sequence(first, step));

  // Print the resulting integers, one per line.
  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
