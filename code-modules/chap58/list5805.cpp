/** @file list5805.cpp */
/** Listing 58-5. Demonstrating How Collation Order Depends on Locale */
import <algorithm>;
import <iostream>;
import <iterator>;
import <locale>;
import <string>;
import <vector>;

void sort_words(std::vector<std::string> words, std::locale loc)
{
  std::ranges::sort(words, loc);
  std::cout << loc.name() << ":\n";
  std::ranges::copy(words,
            std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main()
{
  std::vector<std::string> words{ 
    "circus",
    "\u00e5ngstrom",     // ångstrom
    "\u00e7irc\u00ea",   // çircê
    "angle",
    "essen",
    "ether",
    "\u00e6ther",        // æther
    "aether",
    "e\u00dfen"         // eßen
  };
  sort_words(words, std::locale::classic());
  sort_words(words, std::locale{"en_GB.utf8"});  // Great Britain
  sort_words(words, std::locale{"no_NO.utf8"});  // Norway
}
