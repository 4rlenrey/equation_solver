#include "../include/window.h"

Ewindow::Ewindow(int size_x, int size_y, std::string title)
{
	this->window.create(sf::VideoMode(size_x, size_y), title);
	run();
}

void Ewindow::run()
{
	while (this->window.isOpen())
	{
		sf::Event event;
		while (this->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->window.close();
		}

		this->window.clear();
		this->window.display();
	}
}