#include <fstream>
#include <istream>
#include <limits>
#include <map>
#include <ostream>

#include "calc_error.hpp"
#include "node.hpp"
#include "variables.hpp"

namespace {
  using symbol_table = std::map<std::string, node, std::less<>> ;
  std::vector<symbol_table> symbol_tables{ {
      { "pi", 3.14159265358979323846 },
      { "e",  2.71828182845904523536 }
	}
  };
}

local_symbol_table::local_symbol_table()
{
  symbol_tables.emplace_back();
}

local_symbol_table::~local_symbol_table()
{
  symbol_tables.pop_back();
}

bool find_symbol(std::string_view name, node& value)
{
  for (auto&& symbol_table : symbol_tables) {
	if (auto iterator{ symbol_table.find(name) }; iterator != symbol_table.end())
	{
      value = iterator->second;
      return true;
    }
  }
  return false;
}

node get_variable(std::string_view name)
{
  node result{};
  if (not find_symbol(name, result))
    return node();
  else if (result.get_parameters().empty())
    return result;
  else
    throw function_error{std::string{name}, result.get_parameters().size(), 0};
}

void set_variable(std::string name, node value)
{
  symbol_tables.back()[std::move(name)] = std::move(value);
}

node get_function(std::string_view name)
{
  node result{};
  if (not find_symbol(name, result))
    throw no_such_function{std::string{name}};
  else
    return result;
}

void set_function(std::string name, node value)
{
  set_variable(std::move(name), std::move(value));
}

void save_library(std::string const& filename)
{
  std::ofstream stream{filename};
  if (not stream)
    throw file_error{filename};
  // Be sure to save numbers with maximum precision.
  stream.precision(std::numeric_limits<double>::digits10);
  stream << ":library:\n";
  for (auto const& symbol : symbol_tables.front())
  {
    stream << symbol.first << ' ';
    symbol.second.save(stream);
    if (stream.fail())
      throw file_error{filename};
  }
  stream << "*\n";
  stream.close();
  if (stream.fail())
    throw file_error{filename};
}

void load_library(std::string const& filename)
{
  std::ifstream stream{filename};
  if (not stream)
    throw file_error{filename};
  std::string token{};
  if (not std::getline(stream, token))
    throw calc_error{filename + ": is empty"};
  if (token != ":library:")
    throw calc_error{filename + ": is not a calculator library file"};
  while (stream >> token) {
    if (token == "*")
      return;
    else
      set_variable(std::move(token), node{stream});
  }
}
