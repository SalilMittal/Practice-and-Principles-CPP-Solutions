#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

const std::string IMG_DIR = "../../../includes/graphics/images/";

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 1000, 800, "Canvas" };

	int box = 100;
	int x = 800, y = 800;
	Lines grid;

	for (int i = 1; i <= 8; i++) grid.add({i * box, 0}, {i*box, y});
	for (int i = 1; i <= 8; i++) grid.add({0, i * box}, {x, i * box});
	win.attach(grid);

	Vector_ref<Graph_lib::Rectangle> diag_sq;
	for (int i = 0; i < 8; i++) {
		diag_sq.push_back(new Graph_lib::Rectangle{ {box * i, box * i}, box, box });
		Graph_lib::Rectangle& last_el = diag_sq[diag_sq.size() - 1];
		last_el.set_fill_color(Color::red);
		last_el.set_color(Color::invisible);

		win.attach(last_el);
	}

	std::vector<Point> img_points{ {300, 0}, {500, 200}, {0, 300}, {200, 500} };
	std::string img_src = IMG_DIR + "police_bear.gif";

	Image i1{ img_points[0], img_src };
	Image i2{ img_points[1], img_src };
	Image i3{ img_points[2], img_src };
	Image i4{ img_points[3], img_src };

	win.attach(i1);
	win.attach(i2);
	win.attach(i3);
	win.attach(i4);

	std::string charac_src = IMG_DIR + "cheems.gif";

	for(int i = 0; i < 8; i++) 
		for (int j = 0; j < 8; j++) {
			Image character{ {j*box, i*box}, charac_src };
			win.attach(character);
			win.wait_for_button();
		}

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}