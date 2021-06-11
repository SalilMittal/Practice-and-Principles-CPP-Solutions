#include "Arc.h"

namespace Graph_lib {
	Arc::Arc(Point p, int w, int h, double angle) : Ellipse(p, w, h), angle{ angle } {
		if (angle > 360 || angle < 0) throw std::runtime_error("Invalid Fraction");
	}

	void Arc::draw_lines() const {
		if (color().visibility())
			fl_arc(Ellipse::center().x, Ellipse::center().y, 2 * Ellipse::minor(), 2 * Ellipse::major(), 0, angle);
	}
}