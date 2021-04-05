#include "../include/window.h"

bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp)
{
	if (sprite.contains(mp))
		return true;
	return false;
}

Ewindow::Ewindow(int size_x, int size_y, std::string title)
{
	this->window.create(sf::VideoMode(size_x, size_y), title);

	Ebutton button(sf::Vector2f(0, 0), sf::Vector2f(100, 100), "Button", 20);

	run();
}

void Ewindow::run()
{
	while (this->window.isOpen())
	{
		poll_events();

		this->window.clear();
		draw();
		this->window.display();
	}
}

void Ewindow::poll_events()
{
	while (this->window.pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window.close();
		else if (this->event.type == sf::Event::MouseButtonPressed)
		{
			check_clicks();
		}
	}
}

void Ewindow::draw()
{
	for (auto &obj : Ecomponent::ecomponents) //draw all components in a static vector
	{
		this->window.draw(*obj);
	}
}

void Ewindow::check_clicks()
{
	for (auto &obj : Efocusable::efocusables) //chceck all components in a static vector
	{
		if(obj->rectangle.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			obj->activate();
		else
			obj->deactivate();
	}
}