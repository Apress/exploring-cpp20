/** @file list6303.hh */
/** Listing 63-3. The variables Module */
// export module variables;

#include <ranges>
#include <regex>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> variables;

/*export*/ void define_variable(std::string const& name, std::string const& value)
{
    variables[name] = value;
}

std::string const empty_string;

/*export*/ std::string const& lookup_variable(std::string const& name)
{
    if (auto var = variables.find(name); var == variables.end())
        return empty_string;
    else
        return var->second;
}

/*export*/ std::string expand_variables(std::string const& input)
{
    static const std::regex regex{ "\\$(?:\\$|\\(([\\w.-_]+)\\))" };
    std::string result{};
    auto prefix_begin{ input.begin() };
    auto begin{ std::sregex_iterator{input.begin(), input.end(), regex} };
    auto end{ std::sregex_iterator{} };
    bool matched{false};
    using subrange = std::ranges::subrange<std::sregex_iterator>;
    for (auto const& match: subrange(begin, end)){
        // Copy the string prior to the match
        result.append(prefix_begin, match[0].first);
        prefix_begin = match[0].second;
        if (match[1].matched)
        {
            result += lookup_variable(match[1].str());
            matched = true;
        }
        else
            result += '$'; // no variable, so the regex matched $$
    }
    // copy rest of unmatched string
    result.append(prefix_begin, input.end());
    if (not matched)
        return result;

    // try matching again.
    return expand_variables(result);
}
