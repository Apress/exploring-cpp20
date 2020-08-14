/** @file list4810.cpp */
/** Listing 48-10. Throwing system_error For a File-Open Error */
#include <cerrno>
import <fstream>;
import <iostream>;
import <string>;
import <system_error>;

std::size_t count_words(std::string const& filename)
{
  std::ifstream file(filename);
  if (not file)
    throw std::system_error(errno, std::system_category(), filename);
  std::size_t count{0};
  std::string word;
  while (file >> word)
    ++count;
  return count;
}

int main()
{
  try
  {
    std::cout << count_words("Not a Real File Name") << '\n';
  }
  catch (std::exception const& ex)
  {
    std::cerr << ex.what() << '\n';
  }
}
