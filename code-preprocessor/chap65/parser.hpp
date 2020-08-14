#ifndef PARSER_HPP_
#define PARSER_HPP_

/** @file list6307.cc */
/** Listing 63-7. The parser Module */
// export module parser;

#include <iostream>
#include <regex>
#include <string>

#include "artifact.hpp"
#include "depgraph.hpp"

static const std::regex regex{
    "^[ \t]*"
    "(?:"
        "#.*"                                        "|"
        "[ \t]*(\\S+)[ \t]*=[ \t]*(.*)"              "|"
        "(\\S+)[ \t]*:[ \t]*(\\S+)[ \t]*=[ \t]*(.*)" "|"
        "(\\S+)[ \t]*:[ \t]*(\\S+)[ \t]*(?:#.*)?"
    ")?$"
  };

void parse(std::istream& stream, dependency_graph& graph)
{
  bool okay{true};
  std::string line{};
  std::size_t line_number{};
  while (std::getline(stream, line))
  {
    ++line_number;
    std::smatch match;
    if (std::regex_match(line, match, regex))
    {      if (match[1].matched)
        // var=value
        global_variables.define(match[1].str(), match[2].str());
      else if (match[3].matched) {
        // target: var=value
        auto target_name{ global_variables.expand(match[3].str()) };
        auto target{graph.lookup_artifact(target_name)};
        target.define(match[4].str(), target.expand(match[5].str()));
      }
      else if (match[6].matched) {
        // target: dependency
        auto target_name{ global_variables.expand(match[6].str()) };
        auto target{target_name};
        auto dependency{
            graph.lookup_artifact(target).expand(match[7].str())
        };
        graph.store_dependency(target, dependency);
      }
      // else comment or blank line
    }
    else
    {
      // Input line cannot be parsed.
      std::cerr << "line " << line_number << ": parse error\n";
      okay = false;
      // Keep going in case there are more errors.
    }
  }

  if (not okay)
    throw std::runtime_error("Cannot continue due to parse errors");
}

#endif // PARSER_HPP_
