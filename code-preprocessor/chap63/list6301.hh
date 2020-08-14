/** @file list6301.hh */
/** Listing 63-1. Parsing With a Regular Expression */
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <ranges>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "artifact.hpp"
#include "topsort.hpp"

class dependency_graph
{
public:
  using graph_type = std::unordered_map<artifact*,
                         std::unordered_set<artifact*>>;

  void store_dependency(artifact* target, artifact* dependency)
  {
    graph_[dependency].insert(target);
    graph_[target]; // ensures that target is in the graph
  }

  graph_type const& graph() const { return graph_; }

  template<class OutIter>
  requires std::output_iterator<OutIter, artifact*>
  void sort(OutIter sorted)
  const
  {
    topological_sort(graph_, sorted);
  }

  artifact* lookup_artifact(std::string const& name)
  {
    auto a( artifacts_.find(name) );
    if (a != artifacts_.end())
      return &a->second;
    else
    {
      auto [iterator, inserted]{ artifacts_.emplace(name, name) };
      return &iterator->second;
    }
  }

private:
  graph_type graph_;
  std::map<std::string, artifact> artifacts_;
};

int main()
{
  dependency_graph graph{};

  static const std::regex regex{
      "^[ \t]*(?:#.*|(\\S+)[ \t]*:[ \t]*(\\S+)[ \t]*(?:#.*)?)?$"
  };

  std::string line{};
  std::size_t line_number{};
  while (std::getline(std::cin, line))
  {
    ++line_number;
    std::smatch match;
    if (std::regex_match(line, match, regex))
    {
      // Skip comments and blank lines.
      if (match[1].matched) {
        auto target{graph.lookup_artifact(match[1].str())};
        auto dependency{graph.lookup_artifact(match[2].str())};
        graph.store_dependency(target, dependency);
      }
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
