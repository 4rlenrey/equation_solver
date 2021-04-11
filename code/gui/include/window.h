#pragma once

#include "component.h"
#include "components/button.h"
#include "components/text_box.h"
#include "../../Core/include/core.h"

class Ewindow
{
	sf::Event event;
	sf::RenderWindow window;
	sf::RectangleShape background;
	Ebutton *confirm_equation;
	Etext_box *equation_box;

public:
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
	std::pair<int,int> range;
	std::vector<std::string> values;
};

namespace Ehandle_core
{
	void draw_funct( Etext_box*);
};