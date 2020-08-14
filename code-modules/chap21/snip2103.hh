/** @file snip2103.hh */
/** Code Snippet 21-3 */
void print_vector(std::vector<int> const& v)
{
  std::cout << "{ ";
  std::ranges::copy(v, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "}\n";
}
