/** @file list4802.cpp */
/** Listing 48-2. A Bad Way to Access an Element of a Vector */
import <iostream>;
import <vector>;

int main()
{
  std::vector<int> data{ 10, 20 };
  data[5] = 0;
  std::cout << data[5] << '\n';
}
