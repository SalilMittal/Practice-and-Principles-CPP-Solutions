#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include "Star.h"

const std::string IMG_DIR = "../../../includes/graphics/images/";

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };


	Graph_lib::Star star{ {300, 200}, 150, 50, 200};
	star.set_fill_color(Color::yellow);
	win.attach(star);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}