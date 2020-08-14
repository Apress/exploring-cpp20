/** @file snip4801.hh */
/** Code Snippet 48-1 */
try {
  throw std::runtime_error("oops");
} catch (std::runtime_error const& ex) {
  std::cerr << ex.what() << '\n';
}
