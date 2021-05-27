#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <string>

void skip_to_int() {
    // not of type int
    if(std::cin.fail()) {
        std::cin.clear(); // clear errors
        for(char ch; std::cin >> ch;) { // throw away non digits
            if(isdigit(ch) || ch=='-') { // valid input
                std::cin.unget(); // puts a value back into input stream - not empty
                return;
            }
        }
    }
    throw std::runtime_error("No input");
}


int main() {
    std::cout << "Enter a number 1-10 inclusive: ";
    int n = 0;

    while(true) {
        if(std::cin >> n) {
            if(n >= 1 && n <= 10) break;
            std::cout << "Out of range. Retry: ";
        } else {
            std::cout << "NaN. Retry: ";
            skip_to_int();
        }
    }
    // correct input
}