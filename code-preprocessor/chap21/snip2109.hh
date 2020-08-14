/** @file snip2109.hh */
/** Code Snippet 21-9 */
void print_vector(std::vector<int> const& v)
{
  std::cout << "{ ";
  std::string separator{};
  for (std::vector<int>::const_iterator i{v.begin()}, end{v.end()}; i != end; ++i)
  {
    std::cout << separator << *i;
    separator = ", ";


  }
  std::cout << "}\n";
}
