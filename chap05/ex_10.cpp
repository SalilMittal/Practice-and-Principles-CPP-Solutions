/* Modify the program from exercise 8 to use double instead of int.
Also, make a vector of doubles containing the N–1 differences
between adjacent values and write out that vector of differences. */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    try {
        int n;
        std::cout << "Enter the number of values: ";
        std::cin >> n;
        if(!std::cin) throw std::runtime_error("Invalid Input");
        std::vector<double> v;
        std::cout << "Enter values (end with'|'): ";
        for(double x; std::cin >> x;) v.push_back(x);

        if(v.size() != n) throw std::runtime_error("You entered wrong number of inputs");

        double sum = 0;
        std::vector<double> difs;

        for(int i = 0; i < v.size(); i++) {
            sum += v[i];
            if(i == 0) continue;
            difs.push_back(v[i] - v[i-1]);
        }

        if(sum > std::numeric_limits<double>::max()) throw std::runtime_error("Sum cannot be  represented as DOUBLE");

        std::cout << "Sum of the " << n << " numbers is " << sum << "\n";
        std::cout << "Difs: ";
        for(double x : difs) std::cout << x << " ";
        return 0;
    } catch(std::exception& e) {
        std::cerr << e.what();
    }
}