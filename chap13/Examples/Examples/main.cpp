#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
//#include "Gui.h"

const std::string IMG_DIR = "../../../includes/graphics/images/";

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point T_L { 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ T_L, 600, 400, "Lines object" };

	/*Line horizontal{ x , {200, 100} };
	Line vertical{ {150, 50}, {150, 150} };*/

	/*Lines lines;
	lines.add({ 100, 100 }, { 200, 100 });
	lines.add({ 150, 50 }, { 150, 150 });
	win.attach(lines);*/

	/*int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;

	Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)
		grid.add({ x, 0 }, { x, y_size });
	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add({ 0, y }, { x_size, y });

	grid.set_style(Line_style{ Line_style::dot, 2});
	grid.set_color(Color::red);
	win.attach(grid);*/

	//Graph_lib::Rectangle r1{ {100, 100}, {150, 140} };
	//Graph_lib::Rectangle r2{ {110, 110}, {170, 180} };
	//r1.set_fill_color(Color::red);
	//r2.set_fill_color(Color::white);
	//win.attach(r1);
	//win.attach(r2);

	//win.put_on_top(r1);

	/*Vector_ref<Graph_lib::Rectangle> rect;

	Graph_lib::Rectangle rect1{ Point{100, 200}, Point{200, 300} };
	rect.push_back(new Graph_lib::Rectangle{Point{50, 60}, Point{80, 90}});
	rect.push_back(rect1);

	for (int i = 0; i < rect.size(); i++) rect[i].move(10, 10);*/

	Vector_ref<Graph_lib::Rectangle> vr;

	for(int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++) {
			vr.push_back(new Graph_lib::Rectangle{Point{i * 20, j * 20}, 20, 20 });
			Graph_lib::Rectangle& last_el = vr[vr.size() - 1];
			last_el.set_color(Color::invisible);
			last_el.set_fill_color(Color{ i * 16 + j });
			//win.attach(last_el);
		}

	/*Graph_lib::Ellipse e1{ {200, 200}, 50, 50};
	Graph_lib::Ellipse e2{ {200, 200}, 100, 50 };
	Graph_lib::Ellipse e3{ {200, 200}, 100, 150 };
	win.attach(e1);
	win.attach(e2);
	win.attach(e3);*/

	std::string rita_src = IMG_DIR + "rita.jpg";
	std::string rita_path_src = IMG_DIR + "rita_path.gif";
	Image rita{ Point{0,0}, rita_src};
	Image path{ Point{0,0}, rita_path_src };
	path.set_mask({50, 250}, 600, 400);

	win.attach(path);
	win.attach(rita);

	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}