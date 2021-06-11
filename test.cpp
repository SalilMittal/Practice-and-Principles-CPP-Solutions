#include <iostream>
#include <vector>
#include <cmath>

int main() {
    double x1 = 0, y1 = 0;
    double x2 = 3, y2 = 4;
    double distance = sqrt(pow((x1 - y1), 2) + pow((x2 - y2), 2));
    const double PI = atan(1) * 4;
    double angle = 60;
    const double radians = angle*(PI/180);
    double x3 = x1 + ((distance / 2) * sin(radians));
    double y3 = y1 + ((distance / 2) * cos(radians));
    std::cout << x3 << " " << y3;
}