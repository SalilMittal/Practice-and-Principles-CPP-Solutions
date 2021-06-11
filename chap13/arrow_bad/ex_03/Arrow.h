#pragma once
#include "Graph.h"
#include <vector>

namespace Graph_lib {
	struct Arrow : Line {
	public:
		Arrow(Point start, Point end);
		Arrow(Point start, Point end, double angle);
		//Arrow(Point start, Point end, char direction);
		//Arrow(Point start, Point end, double angle, char dir);

		bool is_valid_dir(char dir) const;
		bool is_valid_angle(double angle) const;

		void draw_lines() const;
	private:
		Point start;
		Point end;
		double angle = 45;
		char dir = 'e';
	};
};