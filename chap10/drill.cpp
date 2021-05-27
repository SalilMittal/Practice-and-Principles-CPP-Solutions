#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Point {
    double x;
    double y;       
};

std::istream& operator>>(std::istream& is, Point& p) {
    double x, y;
    
    char ch_1, ch_2, ch_3;

    is >> ch_1 >> x >> ch_2 >> y >> ch_3;
    
    if(!is || ch_1 != '(' || ch_2 != ',' || ch_3 != ')') {
        if(ch_1 == '*') return is;
        throw std::runtime_error("Error occured");
    }
    
    p.x = x;
    p.y = y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << '(' << p.x << ',' << p.y << ')' << ' ';
}

int main() {
    std::vector<Point> original_points;
    std::cout << "Original points: \n";
    std::ofstream ost {"drill_io.txt"};

    for(int i = 0; i < 7; i++) {
        Point p {};
        std::cout << "Enter (x,y) pair: ";
        std::cin >> p;
        original_points.push_back(p); 
    }

    for(int i = 0; i < original_points.size(); i++) {
        const Point p = original_points[i];
        ost << p;
        if(i == (original_points.size() - 1)) ost << '*';
        std::cout << p;
    }

    ost.close();

    std::ifstream ist {"drill_io.txt"};
    ist.exceptions(ist.exceptions()|std::ios_base::badbit);
    std::vector<Point> processed_points;
    std::cout << "\nProcessed Points: ";

    for(Point p; ist >> p;) {
        std::cout << p;
        processed_points.push_back(p);
    }

    if(original_points.size() != processed_points.size()) throw std::runtime_error("Sizes not equal!");
}