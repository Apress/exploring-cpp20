/** @file snip5802.hh */
/** Code Snippet 58-2 */
auto const& mget{ std::use_facet<std::money_get<char>>(std::locale{""}) };
