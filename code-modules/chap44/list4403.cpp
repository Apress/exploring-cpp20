/** @file list4403.cpp */
/** Listing 44-3. Using a generate_id Object’s Function Call Operator */
import <iostream>;

import generate_id;
import library;


bool get_movie(std::string& title, int& runtime)
{
  std::cout << "Movie title: ";
  if (not std::getline(std::cin, title))
    return false;
  std::cout << "Runtime (minutes): ";
  if (not (std::cin >> runtime))
    return false;
  return true;
}

int main()
{
  generate_id gen{};           // Create an ID generator
  std::string title{};
  int runtime{};
  while (get_movie(title, runtime))
  {
    movie m(int_to_id(gen()), title, runtime);
    std::cout << "new movie: " << m << '\n';
  }
}
