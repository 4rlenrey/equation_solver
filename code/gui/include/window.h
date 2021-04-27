#pragma once

#include "component.h"
#include "components/button.h"
#include "components/label.h"
#include "components/text_box.h"
#include "components/graph_box.h"
#include "../../Core/include/core.h"

class Ebutton; //forward declaration, will be changed later (probably)

class Ewindow
{
	sf::Event event;
	sf::RenderWindow window;
	sf::RectangleShape background;
	Ebutton *confirm_equation;
	Ebutton *clear_button;
	
	Elabel *labels[3];
public:
	Etext_box *equation_box;
	Etext_box *threads_count_box;
	Etext_box *accuracy_box;
	Egraph_box *graph_box;

	Ewindow(int size_x, int size_y, std::string title);
	void run();
	void draw();
	void update();
	void check_clicks();
	void release_clicks();
	void poll_events();
	~Ewindow();
};

struct Edrawing_packet
{
	std::pair<int, int> range;
	std::vector<std::string> values;
};

namespace Ehandle_core
{
	void draw_funct(Ewindow *);
	void clearwindow(Ewindow *);
};