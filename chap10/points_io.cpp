#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

int main() {
    try {
        std::string iname = "points.txt";
        std::ifstream ist {iname};
        if(!ist) throw std::runtime_error("Could not open file " + iname);

        struct Point {
            int x;
            int y;
        };
        std::vector<Point> points;
        int x;
        int y;

        for(Point p; ist >> x >> y;) {
            points.push_back(Point {x,  y});
        }

        std::ofstream ost {"points_output.txt"};
        if(!ost) throw std::runtime_error("Cant open output file");

        for(Point p : points) ost << "(" << p.x << ", " << p.y << ")\n";
    } catch(std::runtime_error& e) {
        std::cout << e.what();
    }
}