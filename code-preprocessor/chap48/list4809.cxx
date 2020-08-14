/** @file list4809.cxx */
/** Listing 48-9. Throwing an Exception from a noexcept Function */
#include <iostream>
#include <exception>

void function() noexcept
{
  throw std::exception{};
}

int main()
{
  try {
    function();
  } catch (std::exception const& ex) {
    std::cout << "Gotcha!\n";
  }
}
