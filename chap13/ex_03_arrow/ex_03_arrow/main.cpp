#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include "Arrow.h"

const std::string IMG_DIR = "../../../includes/graphics/images/";

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };
	Arrow arrow{ Point{543, 375}, {6, 388}, 8 };
	win.attach(arrow);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}