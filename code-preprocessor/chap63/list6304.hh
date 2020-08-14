/** @file list6304.hh */
/** Listing 63-4. New Program Using depgraph and variables Modules */
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ranges>
#include <regex>
#include <string>
#include <vector>

#include "artifact.hpp"
#include "depgraph.hpp"
#include "variables.hpp"

int main()
{
  dependency_graph graph{};

  static const std::regex regex{
      "^[ \t]*(?:#.*|[ \t]*(\\S+)[ \t]*=[ \t]*(.*)|(\\S+)[ \t]*:[ \t]*(\\S+)[ \t]*(?:#.*)?)?$"
  };

  std::string line{};
  std::size_t line_number{};
  while (std::getline(std::cin, line))
  {
    ++line_number;
    std::smatch match;
    if (std::regex_match(line, match, regex))
    {      if (match[1].matched)
        // variable definition
        define_variable(match[1].str(), match[2].str());
      else if (match[3].matched) {
        // target: dependency
        auto target{expand_variables(match[3].str())};
        auto dependency{expand_variables(match[4].str())};
        graph.store_dependency(target, dependency);
      }
      // else comment or blank line
    }
    else
      // Input line cannot be parsed.
      std::cerr << "line " << line_number << ": parse error\n";
  }

  try {
    // Get the sorted artifacts.
    std::vector<artifact*> sorted{};
    graph.sort(std::back_inserter(sorted));
    // Print in build order, which is reverse of dependency order.
    for (auto artifact : sorted | std::ranges::views::reverse)
    {
      std::cout << artifact->name() << '\n';
    }
  } catch (std::runtime_error const& ex) {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;
  }
}
