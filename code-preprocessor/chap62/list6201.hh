/** @file list6201.hh */
/** Listing 62-1. Topological Sort of a Directed Acyclic Graph */
// export module topsort;
#include <deque>
#include <ranges>
#include <stdexcept>

// Helper function for topological_sort().
template<class Graph, class Nodes>
requires
    std::ranges::range<Graph> and
    requires {
        typename Graph::value_type;
        typename Graph::key_type;
    }
void topsort_clean_graph(Graph& graph, Nodes& nodes)
{
  for (auto iter{std::ranges::begin(graph)}; iter != std::ranges::end(graph);)
  {
    if (iter->second.empty())
    {
      nodes.push_back(iter->first);
      graph.erase(iter++);  // advance iterator before erase invalidates it
    }
    else
      ++iter;
  }
}

/// Topological sort of a directed acyclic graph.
/// A graph is a map keyed by nodes, with sets of nodes as values.
/// Edges run from values to keys. The sorted list of nodes
/// is copied to an output iterator in reverse order.
/// @param graph The graph
/// @param sorted The output iterator
/// @throws std::runtime_error if the graph contains a cycle
/// @pre Graph::key_type == Graph::mapped_type::key_type
/*export*/ template<class Graph, class OutIterator>
requires
    std::ranges::range<Graph> and
    requires {
        typename Graph::value_type;
        typename Graph::key_type;
    }
    and
    std::output_iterator<OutIterator, typename Graph::key_type>
void topological_sort(Graph graph, OutIterator sorted)
{
  std::deque<typename Graph::key_type> nodes{};
  // Start with the set of nodes with no incoming edges.
  topsort_clean_graph(graph, nodes);

  while (not nodes.empty())
  {
    // Grab the first node to process, output it to sorted,
    // and remove it from the graph.
    auto n{nodes.front()};
    nodes.pop_front();
    *sorted = n;
    ++sorted;

    // Erase n from the graph
    for (auto& node : graph)
    {
      node.second.erase(n);
    }
    // After removing n, find any nodes that no longer
    // have any incoming edges.
    topsort_clean_graph(graph, nodes);
  }
  if (not graph.empty())
    throw std::runtime_error("Dependency graph contains cycles");
}
