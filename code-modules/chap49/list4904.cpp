#include <iostream>
#include <vector>
#include "list4904.hh"
int main() {
    std::vector<int> data{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> pattern{ 3, 4, 5 };
    auto find{ search(data.begin(), data.end(), pattern.begin(), pattern.end()) };

    if (find == data.end()) {
        std::cout << "fail\n";
    }
    else if (*find == 3) {
       std::cout << "success\n";
    }
    else {
       std::cout << "fail at " << *find << '\n';
    }
}
