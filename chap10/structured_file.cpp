#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void end_of_loop(std::istream& ist, char term, const std::string& message) {
    if(ist.fail()) {
        ist.clear();
        char ch;
        if(ist >> ch && ch == term) return;
        throw std::runtime_error("IST fail");
    }    
}

int main() {
    std::ifstream ist {"structured_input.txt"};
    ist.exceptions(ist.exceptions() | std::ios_base::badbit);
}