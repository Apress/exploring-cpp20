/** @file list6506.hh */
/** Listing 65-6. New Program Using the parser Module */
#include <iostream>
#include <iterator>
#include <ranges>
#include <stdexcept>
#include <vector>

#include "artifact.hpp"
#include "depgraph.hpp"
#include "parser.hpp"

std::vector<artifact> get_dependency_order()
{
   dependency_graph graph{};
   parse(std::cin, graph);
   std::vector<artifact> sorted;
   graph.sort(std::back_inserter(sorted));
   return sorted;
}

int main()
{
  try {
    std::vector<artifact> build_list{ get_dependency_order() };

    // Print in build order, which is reverse of dependency order.
    for (auto artifact : build_list | std::ranges::views::reverse)
    {
      std::cout << artifact.name() << '\n';
    }
  } catch (std::runtime_error const& ex) {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;
  }
}
