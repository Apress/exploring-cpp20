/** @file list6305.hh */
/** Listing 63-5. Adding Local and Global Maps to the variables Module */
// export module variables;

#include <ranges>
#include <regex>
#include <string>
#include <unordered_map>

class base
{
public:
    virtual ~base() = default;
    virtual std::string const& lookup(std::string const& name) const = 0;

    void define(std::string const& name, std::string const& value)
    {
        map_[name] = value;
    }

    std::string expand(std::string const& input)
    const
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
                result += lookup(match[1].str());
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
        return expand(result);
    }

protected:
    base() = default;
    static const std::string empty_string;
    std::unordered_map<std::string, std::string> map_;
};

const std::string base::empty_string;

class global : public base
{
public:
    std::string const& lookup(std::string const& name)
    const override
    {
        if (auto var = map_.find(name); var == map_.end())
            return empty_string;
        else
            return var->second;
    }
};

// Global variables
/*export*/ global global_variables;

// Target-specific variables
/*export*/ class variables : public base
{
public:
    std::string const& lookup(std::string const& name)
    const override
    {
        if (auto var = map_.find(name); var == map_.end())
            return global_variables.lookup(name);
        else
            return var->second;
    }
};
