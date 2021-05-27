#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream ist {"ex_01_nums.txt"};
    
    int sum = 0;

    for(int x; ist >> x;) {
        sum += x;
    }

    if(ist.fail()) {
        ist.clear();
        char ch;
        if(!(ist >> ch && ch == '*')) throw std::runtime_error("Error");
    }

    std::cout << "Sum = " << sum;
}