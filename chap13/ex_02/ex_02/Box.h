#include "Graph.h"

namespace Graph_lib {
	struct Box : Rectangle {
		using Rectangle::Rectangle;
		void draw_lines() const;
	};
};