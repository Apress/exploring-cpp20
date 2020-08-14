/** @file list6602.cpp */
/** Listing 66-2. Demonstrating the path Class */
#include <filesystem>
#include <format>
#include <iostream>
#include <iterator>

namespace fsys = std::filesystem;

void print_file_type(std::ostream& stream, fsys::path const& path)
{
    auto status{ fsys::symlink_status(path) };
    if (fsys::is_symlink(status)) {
        auto link{ fsys::read_symlink(path) };
        stream << " -> " << link.generic_string();
    }
    else if (fsys::is_directory(status))
        stream << '/';
    else if (fsys::is_fifo(status))
        stream << '|';
    else if (fsys::is_socket(status))
        stream << '=';
    else if (fsys::is_character_file(status))
        stream << "(c)";
    else if (fsys::is_block_file(status))
        stream << "(b)";
    else if (fsys::is_other(status))
        stream << "?";
}

void print_file_info(std::ostream& stream, fsys::path const& path)
{
    std::format_to(std::ostreambuf_iterator<char>(stream),
        "{0:>16} {1:%F %T} ",
        fsys::file_size(path),
        fsys::last_write_time(path));
    stream << path.generic_string();
    print_file_type(stream, path);
    stream << '\n';         
}

int main(int, char** argv)
{
    if (argv[1] == nullptr)
    {
        std::cerr << "usage: " << argv[0] << " FILENAME\n";
        return EXIT_FAILURE;
    }
    fsys::path path{ argv[1] };
    try
    {
        print_file_info(std::cout, path);
    }
    catch(fsys::filesystem_error const& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}
