/* . Quadratic equations are of the form
a · x
2
 + b · x + c = 0
To solve these, one uses the quadratic formula:
There is a problem, though: if b2–4ac is less than zero, then it will
fail. Write a program that can calculate x for a quadratic equation.
Create a function that prints out the roots of a quadratic equation,
given a, b, c. When the program detects an equation with no real
roots, have it print out a message. How do you know that your results
are plausible? Can you check that they are correct? */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <math.h>

int main() {
    double a, b, c;
    std::cout << "Quadratic Solver \n";
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;

    try {
        double discriminant = b*b - 4*a*c;
        if(discriminant < 0) {
            throw std::runtime_error("Imaginary roots");
        } else {
            discriminant = sqrt(discriminant);
        }
        double x1 = (b + discriminant) / (2*a);
        double x2 = (b - discriminant) / (2*a);
        std::cout << "The solutions are: " << x1 << ", " << x2;
        return 0;
    } catch(std::exception& e) {
        std::cerr << e.what();
    }
}