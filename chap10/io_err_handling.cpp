#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

void fill_vector(std::istream& ist, std::vector<int>& v, char terminator) {
    // throw exception on bad state
    ist.exceptions(ist.exceptions() | std::ios_base::badbit); // throws ios_base::failure

    for(int i; ist >> i;) v.push_back(i);
    if(ist.eof()) return;
    ist.clear(); //clear error flag on ist 

    char c;
    ist >> c;

    if(c != terminator) { // unexpected char
        ist.unget();
        ist.clear(std::ios_base::failbit); // reset to fail state
    }
}

int main() {
    try {
        /* std::cout << "Enter a number: ";
        int i = 0;
        std::cin >> i;
        if(!std::cin) {
            if(std::cin.bad()) {
                throw std::runtime_error("state: bad");
            }

            if(std::cin.eof()) {
                std::cout << "------ End of Input -------";
            }

            if(std::cin.fail()) {
                std::cout << "Failed input";
                std::cin.clear();
                // Recover and take input back
            }
        } */
        std::ifstream ist{"terminating_numbers.txt"};
        std::vector<int> v;
        fill_vector(ist, v, '*');
        for(int x : v) std::cout << x << " ";
    } catch(std::runtime_error& e) {
        std::cout << e.what();
    }
}