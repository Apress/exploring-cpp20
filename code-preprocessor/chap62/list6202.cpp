/** @file list6202.cpp */
/** Listing 62-2. First Draft of the Pseudo-make Program */
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "topsort.hpp"

using artifact = std::string; ///< A target, dependency, or both

class dependency_graph
{
public:
  using graph_type=std::unordered_map<artifact, std::unordered_set<artifact>>;

  void store_dependency(artifact const& target, artifact const& dependency)
  {
    graph_[dependency].insert(target);
    graph_[target]; // ensures that target is in the graph
  }

  graph_type const& graph() const { return graph_; }

  template<class OutIter>
  requires std::output_iterator<OutIter, artifact>
  void sort(OutIter sorted)
  const
  {
    topological_sort(graph_, sorted);
  }

private:
  graph_type graph_;
};

int main()
{
  dependency_graph graph{};

  std::string line{};
  while (std::getline(std::cin, line))
  {
    std::string target{}, dependency{};
    std::istringstream stream{line};
    if (stream >> target >> dependency)
      graph.store_dependency(target, dependency);
    else if (not target.empty())
      // Input line has a target with no dependency,
      // so report an error.
      std::cerr << "malformed input: target, " << target <<
                   ", must be followed by a dependency name\n";
    // else ignore blank lines
  }

  try {
    // Get the artifacts in dependency order.
    std::vector<artifact> sorted{};
    graph.sort(std::back_inserter(sorted));
    // Print in build order, which is reverse of dependency order.
    for (auto const& artifact: sorted | std::ranges::views::reverse)
      std::cout << artifact << '\n';
  } catch (std::runtime_error const& ex) {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;
  }
}
