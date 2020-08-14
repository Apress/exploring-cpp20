/** @file list2502.cpp */
/** Listing 25-2. Overloading Functions in the Manner of a Library-Writer */
import <algorithm>;
import <iostream>;
import <locale>;
import <ranges>;
import <string>;
import <string_view>;

bool is_alpha(char ch)
{
  return std::isalpha(ch, std::locale{});
}

bool is_alpha(std::string_view str)
{
  return std::ranges::all_of(str, [](char c) { return is_alpha(c); });
}

char to_lower(char ch)
{
  return std::tolower(ch, std::locale{});
}

std::string to_lower(std::string_view str)
{
  auto data{str | std::views::transform([](char c) { return to_lower(c); })};
  return std::string{ std::ranges::begin(data), std::ranges::end(data) };
}
  
char to_upper(char ch)
{
  return std::toupper(ch, std::locale{});
}

std::string to_upper(std::string str)
{
  for (char& ch : str)
    ch = to_upper(ch);
  return str;
}

int main()
{
  std::string str{};
  while (std::cin >> str)
  {
    if (is_alpha(str))
      std::cout << "alpha\n";
    else
      std::cout << "not alpha\n";
    std::cout << "lower: " << to_lower(str) << "\n"
                 "upper: " << to_upper(str) << '\n';
  }
}
