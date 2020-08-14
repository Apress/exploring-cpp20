/** @file list6308.hh */
/** Listing 63-8. New Program Using the parser Module */
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ranges>
#include <stdexcept>
#include <vector>

#include "artifact.hpp"
#include "depgraph.hpp"
#include "parser.hpp"

int main()
{
  try {
    dependency_graph graph{};
    parse(std::cin, graph);

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
