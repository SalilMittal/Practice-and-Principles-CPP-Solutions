#include "Graph.h"

namespace Graph_lib {
	struct Arc : Ellipse {
	public:
		Arc(Point p, int w, int h, double angle);
		void draw_lines() const;
	private:
		double angle;
	};
}