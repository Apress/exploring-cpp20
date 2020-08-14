/** @file snip2110.hh */
/** Code Snippet 21-10 */
int prompted_read(std::string_view prompt)
{
  std::cout << prompt;
  int x{0};
  std::cin >> x;
  ignore_line();
  return x;
}
