/** @file list6018.cpp */
/** Listing 60-18. Calling std::format to Format a String */
import <format>;
import <iostream>;

int main()
{
  std::cout << std::format("{0:x}\n{1:.10e}\n{2}\n", 42, 42.0, true);
}
