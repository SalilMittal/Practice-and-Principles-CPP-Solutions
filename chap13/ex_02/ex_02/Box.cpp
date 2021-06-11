#include "Graph.h"
#include "Box.h"

namespace Graph_lib {
	void Box::draw_lines() const {
		const Point midw = Rectangle::west();
		const double angle = 40;

		Rectangle::draw_lines();
		//const double r = (0.25) * (Rectangle::height());

		const double r = Rectangle::height() / 2.0;
		std::cout << r;

		//100 125
		fl_arc(midw.x - r/2.0, midw.y - r, r, r, 90, 180);

		//fl_arc(midw.x - r / 2.0, midw.y + r, r, r, 0, 90);

	}
};