/** @file list6019.cpp */
/** Listing 60-19. Calling std::format_to to Format Output */
import <format>;
import <iostream>;
import <iterator>;

int main()
{
  std::format_to(std::ostreambuf_iterator<char>(std::cout),
     "{0:x}\n{1:.10e}\n{2}\n", 42, 42.0, true);
}
