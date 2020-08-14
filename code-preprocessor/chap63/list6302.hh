/** @file list6302.hh */
/** Listing 63-2. The depgraph Module */
// export module depgraph;

#include <iterator>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "artifact.hpp"
#include "topsort.hpp"

/*export*/ class dependency_graph
{
public:
  using graph_type = std::unordered_map<artifact*,
                         std::unordered_set<artifact*>>;

  void store_dependency(std::string const& target_name,
      std::string const& dependency_name)
  {
    auto target{ lookup_artifact(target_name) };
    auto dependency{ lookup_artifact(dependency_name) };
    store_dependency(target, dependency);
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
    auto a{ artifacts_.find(name) };
    if (a != artifacts_.end())
      return &a->second;
    else
    {
      auto [iterator, inserted]{ artifacts_.emplace(name, name) };
      return &iterator->second;
    }
  }

private:
  void store_dependency(artifact* target, artifact* dependency)
  {
    graph_[dependency].insert(target);
    graph_[target]; // ensures that target is in the graph
  }

  graph_type graph_;
  std::map<std::string, artifact> artifacts_;
};
