/** @file list6002.hh */
/** Listing 60-2. Implementing the Debug Function */
module debug;
import <fstream>;
import <ostream>;
import <stdexcept>;

void debug(std::string_view str)
{
   std::ofstream stream{"debug.txt", std::ios_base::out | std::ios_base::app};
   if (not stream)
      throw std::runtime_error("cannot open debug.txt");
   stream.exceptions(std::ios_base::failbit);
   stream << str << '\n';
   stream.close();
}


