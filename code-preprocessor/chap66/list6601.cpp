/** @file list6601.cpp */
/** Listing 66-1. Demonstrating the path Class */
#include <filesystem>
#include <iostream>

namespace fsys = std::filesystem;

int main()
{
   std::string line;
   while (std::getline(std::cin, line))
   {
      fsys::path path{line};
      std::cout << 
         "root-name:      " << path.root_name() << "\n"
         "root-directory: " << path.root_directory() << "\n"
         "relative-path:  " << path.relative_path() << "\n"
         "parent-path:    " << path.parent_path() << "\n"
         "filename:       " << path.filename() << "\n"
         "stem:           " << path.stem() << "\n"
         "extension:      " << path.extension() << "\n"
         "generic path:   " << path.generic_string() << "\n"
         "native path:    " << path.string() << '\n';
        
      fsys::path newpath;
      newpath = path.root_path() / "top" / "subdir" / "stem.ext";
      std::cout << "newpath = " << newpath << '\n';
      newpath.replace_filename("newfile.newext");
      std::cout << "newpath = " << newpath << '\n';
      newpath.replace_extension(".old");
      std::cout << "newpath = " << newpath << '\n';
      newpath.remove_filename();
      std::cout << "newpath = " << newpath << '\n';
   }
}
