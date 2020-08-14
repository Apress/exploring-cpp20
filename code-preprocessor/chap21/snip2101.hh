/** @file snip2101.hh */
/** Code Snippet 21-1 */
std::vector<int> add(std::vector<int> v, int a)
{
  std::vector<int> result{};
  for (auto i : v)
    result.emplace_back(i + a);
  return result;
}
