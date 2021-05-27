#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string contents;
    std::ifstream ifs_1 {"merge_01.txt"};
    std::ifstream ifs_2 {"merge_02.txt"};
    std::ofstream ofs {"merge_result.txt"};

    for(char ch; ifs_1 >> ch;) ofs << ch;
    for(char ch; ifs_2 >> ch;) ofs << ch;
}