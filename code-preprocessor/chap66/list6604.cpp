/** @file list6604.cpp */
/** Listing 66-4. Recursing Into Directories */
#include <filesystem>
#include <format>
#include <iostream>
#include <iterator>
#include <system_error>

namespace fsys = std::filesystem;

void print_file_type(std::ostream& stream, fsys::directory_entry const& entry)
{
    auto status{ entry.symlink_status() };
    if (fsys::is_symlink(status)) {
        std::error_code ec;
        auto link{ fsys::read_symlink(entry.path(), ec) };
        if (ec)
            stream << ": " << ec.message();
        else
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

// There may be many reasons why a file has no size, e.g., it is
// a directory. So don't treat it as an error--just return zero.
uintmax_t get_file_size(fsys::directory_entry const& entry)
{
    std::error_code ec;
    auto size{ entry.file_size(ec) };
    if (ec)
        return 0;
    else
        return size;
}

// Similarly, return a false timestamp for any error.
fsys::file_time_type get_last_write_time(fsys::directory_entry const& entry)
{
    std::error_code ec;
    auto time{ entry.last_write_time(ec) };
    if (ec)
        return fsys::file_time_type{};
    else
        return time;
}

void print_file_info(std::ostream& stream, fsys::directory_entry const& entry)
{
    std::format_to(std::ostreambuf_iterator<char>(stream),
        "{0:>16} {1:%F %T} {2}",
        get_file_size(entry),
        get_last_write_time(entry),
        entry.path().generic_string());
    print_file_type(stream, entry);
    stream << '\n';         
    if (not entry.is_symlink() and entry.is_directory())    {
        for (auto&& entry : fsys::directory_iterator{entry.path()})
            print_file_info(stream, entry);
    }
}

int main(int, char** argv)
{
    if (argv[1] == nullptr or std::string_view(argv[1]) == "--help")
    {
        std::cerr << "usage: " << argv[0] << " FILENAME\n";
        return EXIT_FAILURE;
    }
    while (*++argv != nullptr)
    {
        fsys::path path{ *argv };
        std::error_code ec;
        fsys::directory_entry entry{ path, ec };
        if (ec)
            std::cout << *argv << ": " << ec.message() << '\n';
        else
            print_file_info(std::cout, entry);
    }
}
