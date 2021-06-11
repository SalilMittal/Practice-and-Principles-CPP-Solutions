#include "Graph.h"

namespace Graph_lib {
	struct Reg_hex : Polygon {
	public:
		Reg_hex(Point center, int distance);
	private:
		Point center;
		int distance;
	};
};