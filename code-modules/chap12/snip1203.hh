/** @file snip1203.hh */
/** Code Snippet 12-3 */
if ("help" > "hello") std::cout << "Bad. Bad. Bad. Don’t do this!\n";
if (std::string("help") > "hello") std::cout << "this works\n";
if ("help" > std::string("hello")) std::cout << "this also works\n";
if (std::string("help") > std::string("hello")) std::cout << "and this works\n";
