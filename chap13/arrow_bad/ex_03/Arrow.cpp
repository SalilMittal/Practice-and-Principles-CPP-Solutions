#include "Arrow.h"
#include <vector>
#include <cmath>
#include <iostream>

const double PI = atan(1) * 4;

namespace Graph_lib {
	Arrow::Arrow(Point start, Point end) : Line(start, end), start{ start }, end{end} {
		
	}

	/*Arrow::Arrow(Point start, Point end, char direc) : Line(start, end), dir{direc}, start{ start }, end{ end } {
		if (!is_valid_dir(dir)) throw std::runtime_error("Specify valid arrowhead direction");
	}*/

	Arrow::Arrow(Point start, Point end, double ang) : Line(start, end), angle{ang}, start{ start }, end{ end } {
		if (!is_valid_angle(angle)) throw std::runtime_error("Specify valid angle");
	}

	//Arrow::Arrow(Point start, Point end, double ang, char dir) : Line(start, end), angle{ ang }, start{ start }, end{ end } {
	//	if (!is_valid_angle(angle)) throw std::runtime_error("Specify valid angle");
	//	if (!is_valid_dir(dir)) throw std::runtime_error("Specify valid arrowhead direction");
	//}

	bool Arrow::is_valid_angle(double angle) const { return (angle > 0 && angle < 90);}
	bool Arrow::is_valid_dir(char dir) const { return (dir == 's' || dir == 'e'); }

	void Arrow::draw_lines() const {
		Line::draw_lines();
		const Point top = (dir == 's') ? start : end;
		const double distance = sqrt(pow((start.x - end.x), 2) + pow((start.y - end.y), 2));	
		const double arrow_len = distance / 10;
		const double radians = (angle)*(PI/180);
		
		const double stick_slope = (end.y - start.y) / float(end.x - start.x);

		/**
		 * Case 1 P
		 * 
		*/
		const double p_slope = ((-stick_slope) - tan(radians)) / ((tan(radians)*stick_slope) - 1);

		const double p_a = 1 + pow(p_slope, 2);
		const double p_b = (-2*top.x) - (2 * (top.x) * pow(p_slope, 2));
		const double p_c = -pow(arrow_len, 2) + pow(top.x, 2) + pow(top.x, 2)*pow(p_slope, 2);
		const double p_disc = sqrt(pow(p_b, 2) - 4*p_a* p_c);
		const double p_x_1 = (-p_b + p_disc) / (2 * p_a);
		const double p_x_2 = (-p_b - p_disc) / (2 * p_a);

		const double p_y_1 = p_slope * p_x_1 - p_slope * top.x + top.y;
		const double p_y_2 = p_slope * p_x_2 - p_slope * top.x + top.y;

		double p_x;
		double p_y;

		if (abs(p_y_1) > abs(top.y)) {
			p_x = p_x_2;
			p_y = p_slope * p_x - p_slope * top.x + top.y;
		}
		else {
			p_x = p_x_1;
			p_y = p_slope * p_x - p_slope * top.x + top.y;
		}

		std::cout << "(" << p_x << ", " << p_y  << ")\n";


		/**
		 * Case 1 Q
		 *
		*/

		const double q_slope = (stick_slope - tan(radians)) / (stick_slope + 1);

		const double q_a = 1 + pow(q_slope, 2);
		const double q_b = (-2 * top.x) - (2 * (top.x) * pow(q_slope, 2));
		const double q_c = -pow(arrow_len, 2) + pow(top.x, 2) + pow(top.x, 2) * pow(q_slope, 2);
		const double q_disc = sqrt(pow(q_b, 2) - 4 * q_a * q_c);
		const double q_x_1 = (-q_b + q_disc) / (2 * q_a);
		const double q_x_2 = (-q_b - q_disc) / (2 * q_a);

		const double q_y_1 = q_slope * q_x_1 - q_slope * top.x + top.y;
		const double q_y_2 = q_slope * q_x_2 - q_slope * top.x + top.y;

		double q_x;
		double q_y;

		if (abs(q_y_1) > abs(top.y)) {
			q_x = q_x_2;
			q_y = q_slope * q_x - q_slope * top.x + top.y;
		}
		else {
			q_x = q_x_1;
			q_y = q_slope * q_x - q_slope * top.x + top.y;
		}

		std::cout << "(" << q_x << ", " << q_y << ")\n";
		std::cout << "(" << start.x << ", " << start.y << ")\n";
		std::cout << "(" << end.x << ", " << end.y << ")\n";

		fl_line(top.x, top.y, p_x, p_y);
		fl_line(top.x, top.y, q_x, q_y);
	}
};