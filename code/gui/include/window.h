#pragma once

#include "component.h"
#include "components/button.h"
#include "components/text_box.h"
#include "../../Core/include/core.h"

class Ewindow
{
	sf::Event event;
	sf::RenderWindow window;

public:
	Ewindow(int size_x, int size_y, std::string title);
	void run();
	void draw();
	void update();
	void check_clicks();
	void release_clicks();
	void poll_events();
};

struct Edrawing_packet
{
	std::pair<int,int> range;
	std::vector<std::string> values;
};

namespace Ehandle_core
{
	void draw_funct();
	std::string get_equation(const Etext_box& box);
	Edrawing_packet get_drawing_packet(std::string equation);
};