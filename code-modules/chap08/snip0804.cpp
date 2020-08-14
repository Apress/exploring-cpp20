#include <format>
#include <iostream>
int main(int, char** argv) {
std::cout <<
std::format(*++argv ? *argv : "'{0:c}': {0:#04x} {0:#010b} |{0:{1}d}| {2:s}\n", '*', 4, "str")
;
}
