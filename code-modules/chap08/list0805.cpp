/** @file list0805.cpp */
/** Listing 8-5. Program to Produce Formatted Output  */
import <iomanip>;
import <iostream>;

int main()
{
  using namespace std;

  cout << setfill('0') << setw(6) << 42 << '\n';
  cout << left         << setw(6) << 42 << '\n';
  cout << 42 << '\n';
  cout << setfill('-') << setw(4) << -42 << '\n';
}
