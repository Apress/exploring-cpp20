/** @file list4003.cpp */
/** Listing 40-3. Copying vs. Moving */
import <iostream>;
import <utility>;
import <vector>;

void print(std::vector<int> const& vector)
{
  std::cout << "{ ";
  for (int i : vector)
    std::cout << i << ' ';
  std::cout << "}\n";
}

int main()
{
  std::vector<int> source{1, 2, 3 };
  print(source);
  std::vector<int> copy{source};
  print(copy);
  std::vector<int> move{std::move(source)};
  print(move);
  print(source);
}
