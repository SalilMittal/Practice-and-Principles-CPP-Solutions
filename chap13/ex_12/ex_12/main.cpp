#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	const double PI = atan(1) * 4;
	const int r = 100;
	const Point cent{ 100, 100 };
	Circle c1{ cent, r };
	c1.set_color(Color::green);
	win.attach(c1);

	for (double i = 0; i < 2*PI; i+=0.1) {
		int x = cent.x + int(r * cos(i));
		int y = cent.y - int(r * sin(i));
		Mark m{ {x, y}, '*' };
		m.set_color(Color::red);
		std::cout << x << " " << y << "\n";
		win.attach(m);
		win.wait_for_button();
	}

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}