#include "../include/window.h"

Ewindow::Ewindow(int size_x, int size_y, std::string title)
{
	this->window.create(sf::VideoMode(size_x, size_y), title);

	Ebutton button(sf::Vector2f(0, 0), sf::Vector2f(100, 100), "Test", 20);
	run();

}

void Ewindow::run()
{
	while (this->window.isOpen())
	{
		while (this->window.pollEvent(this->event))
		{
			if (this->event.type == sf::Event::Closed)
				this->window.close();
		}
		this->window.clear();
		draw();
		this->window.display();
	}
}

void Ewindow::draw()
{
	for (auto &obj : Ecomponent::ecomponents) //draw all components in a static vector
	{
		this->window.draw(*obj);
	}
}