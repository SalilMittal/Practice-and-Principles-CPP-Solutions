#include "Graph.h"
#include "Reg_hex.h"
#include <vector>
#include <cmath>

const double PI = atan(1) * 4;

namespace Graph_lib {
	Reg_hex::Reg_hex(Point center, int distance) : center{ center }, distance{ distance } {
		if (distance <= 0) throw std::runtime_error("Distance must be finite");
		std::vector<Point> points;
		points.push_back({ center.x, center.y - distance });
		points.push_back({ center.x + distance, center.y - int(distance * cos(PI / 3)) });
		points.push_back({ center.x + distance, center.y + int(distance * cos(PI / 3)) });
		points.push_back({ center.x, center.y + distance });
		points.push_back({ center.x - distance, center.y + int(distance * cos(PI / 3)) });
		points.push_back({ center.x - distance, center.y - int(distance * cos(PI / 3)) });

		for (Point p : points) add(p);
	}
};