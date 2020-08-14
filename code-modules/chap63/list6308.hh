/** @file list6308.hh */
/** Listing 63-8. New Program Using the parser Module */
#include <cstdlib>
import <iostream>;
import <iterator>;
import <ranges>;
import <stdexcept>;
import <vector>;

import artifact;
import depgraph;
import parser;

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
