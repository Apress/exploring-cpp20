/** @file list0102.cpp */
/** Listing 1-2. Testing Your Compiler */
/// Sort the standard input alphabetically.
/// Read lines of text, sort them, and print the results to the standard output.
/// If the command line names a file, read from that file. Otherwise, read from
/// the standard input. The entire input is stored in memory, so don’t try
/// this with input files that exceed available RAM.
///
/// Comparison uses a locale named on the command line, or the default, unnamed
/// locale if no locale is named on the command line.

#include <cerrno>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>
#include <system_error>
#include <vector>

template<class C>
struct text : std::basic_string<C>
{
  using super = std::basic_string<C>;
  constexpr text() noexcept : super{} {}
  text(text&&) = default;
  text(text const&) = default;
  text& operator=(text const&) = default;
  text& operator=(text&&) = default;
  constexpr explicit operator bool() const noexcept {
    return not this->empty();
  }
};

/// Read lines of text from @p in to @p iter. Lines are appended to @p iter.
/// @param in the input stream
/// @param iter an output iterator
template<class Ch>
auto read(std::basic_istream<Ch>& in) -> std::vector<text<Ch>>
{
    std::vector<text<Ch>> result;
    
    text<Ch> line;
    while (std::getline(in, line))
        result.emplace_back(std::move(line));

    return result;
}

/// Main program.
int main(int argc, char* argv[])
try
{
    // Throw an exception if an unrecoverable input error occurs, e.g.,
    // disk failure.
    std::cin.exceptions(std::ios_base::badbit);

    // Part 1. Read the entire input into text. If the command line names a file,
    // read that file. Otherwise, read the standard input.
    std::vector<text<char>> text; ///< Store the lines of text here
    if (argc < 2)
        text = read(std::cin);
    else
    {
        std::ifstream in{argv[1]};
        if (not in)
        {
            std::cout << argv[1] << ": " << std::system_category().message(errno) << '\n';
            return EXIT_FAILURE;
        }
        text = read(in);
    }

    // Part 2. Sort the text. The second command line argument, if present,
    // names a locale, to control the sort order. Without a command line
    // argument, use the default locale (which is obtained from the OS).
    std::locale const& loc{ std::locale(argc >= 3 ? argv[2] : "") };
    std::collate<char> const& collate{ std::use_facet<std::collate<char>>(loc) };
    std::ranges::sort(text,
        [&collate](auto const& a, auto const& b)
        {
            return collate.compare(to_address(cbegin(a)), to_address(cend(a)),
                to_address(cbegin(b)), to_address(cend(b))) < 0;
        }
    );
 
    // Part 3. Print the sorted text.
   for (auto const& line :  text)
      std::cout << line << '\n';
}
catch (std::exception& ex)
{
    std::cerr << "Caught exception: " << ex.what() << '\n';
    std::cerr << "Terminating program.\n";
    std::exit(EXIT_FAILURE);
}
catch (...)
{
    std::cerr << "Caught unknown exception type.\nTerminating program.\n";
    std::exit(EXIT_FAILURE);
}
