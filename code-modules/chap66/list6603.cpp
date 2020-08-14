/** @file list6603.cpp */
/** Listing 66-3. Examining Errors With error_code */
import <filesystem>;
import <format>;
import <iostream>;
import <iterator>;
import <string_view>;
import <system_error>;

namespace fsys = std::filesystem;

void print_file_type(std::ostream& stream, fsys::path const& path, fsys::file_status status)
{
    if (fsys::is_symlink(status)) {
        std::error_code ec;
        auto link{ fsys::read_symlink(path, ec) };
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
uintmax_t get_file_size(fsys::path const& path)
{
    std::error_code ec;
    auto size{ fsys::file_size(path, ec) };
    if (ec.value() != 0)
        return 0;
    else
        return size;
}

// Similarly, return a false timestamp for any error.
fsys::file_time_type get_last_write_time(fsys::path const& path)
{
    std::error_code ec;
    auto time{ fsys::last_write_time(path, ec) };
    if (ec)
        return fsys::file_time_type{};
    else
        return time;
}

void print_file_info(std::ostream& stream, fsys::path const& path)
{
    std::error_code ec;
    auto status{ fsys::symlink_status(path, ec) };
    if (ec)
        stream << path.generic_string() << ": " << ec.message();
    else
    {
        std::format_to(std::ostreambuf_iterator<char>(stream),
            "{0:>16} {1:%F %T} {2}",
            get_file_size(path),
            get_last_write_time(path),
            path.generic_string());
        print_file_type(stream, path, status);
    }
    stream << '\n';         
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
        print_file_info(std::cout, path);
    }
}
