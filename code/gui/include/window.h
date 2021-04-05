#pragma once

#include "component.h"
#include "components/button.h"

class Ewindow
{
	sf::Event event;
	sf::RenderWindow window;

public:
	Ewindow(int size_x, int size_y, std::string title);
	void run();
	void draw();
	void check_clicks();
	void release_clicks();
	void poll_events();
};
