#include <map>
#include <string>
#include <string_view>

#include "variables.hpp"

// An unnamed namespace is private to the source file that contains it.
namespace {
  std::map<std::string, double, std::less<>> variables{
    { "pi", 3.14159265358979323846 },
    { "e",  2.71828182845904523536 }
  };
}

double get_variable(std::string_view name)
{
  if (auto iterator{ variables.find(name) }; iterator != variables.end())
    return iterator->second;
  else
  {
    set_variable(std::string{name}, 0.0);
    return 0.0;
  }
}

void set_variable(std::string name, double value)
{
  variables[std::move(name)] = value;
}
