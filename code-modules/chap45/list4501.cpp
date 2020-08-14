/** @file list4501.cpp */
/** Listing 45-1. Searching for an Integer */
import <algorithm>;
import <iostream>;

import data;

int main()
{
  intvector data{};
  read_data(data);
  write_data(data);
  if(auto iter{std::ranges::find(data, 42)}; iter == data.end())
    std::cout << "Value 42 not found\n";
  else
  {
    *iter = 0;
    std::cout << "Value 42 changed to 0:\n";
    write_data(data);
  }
}
