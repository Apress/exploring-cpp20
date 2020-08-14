#include <fstream>
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::ifstream file{"snip6302.txt"};
    std::string text;
    std::getline(file, text); // skip comment
    std::getline(file, text); // skip comment
    std::getline(file, text);
    text = regex_replace(text, std::regex{"\\t"}, "\t");
    std::regex r{text};
    while (std::getline(std::cin, text)) {
       std::smatch m;
       std::cout << std::boolalpha << regex_match(text, m, r);
       std::cout << " \"" << m[1].str() << "\", \"" << m[2].str() << "\"\n";
    }
}
