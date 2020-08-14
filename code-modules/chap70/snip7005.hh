/** @file snip7005.hh */
/** Code Snippet 70-5 */
for (char_traits::int_type c = std::cin.get();
      not char_traits::eq_int_type(c, char_traits::eof());
      c = std::cin.get())
