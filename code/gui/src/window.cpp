#include "../include/window.h"

void Ehandle_core::draw_funct();

Ewindow::Ewindow(int size_x, int size_y, std::string title)
{
	this->window.create(sf::VideoMode(size_x, size_y), title);
	Ebutton button(sf::Vector2f(0, 200), sf::Vector2f(100, 100), "Generate", 20, Ehandle_core::draw_funct);
	Etext_box box(sf::Vector2f(200, 0), sf::Vector2f(200, 100), 20);

	run();
}
void Ewindow::update()
{
	for (auto &obj : Etext_box::etext_boxes)
	{
		obj->update();
	}
}

void Ewindow::run()
{
	while (this->window.isOpen())
	{
		poll_events();

		this->window.clear();
		update();
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
			check_clicks();
		else if (this->event.type == sf::Event::MouseButtonReleased) //poor implementation
			release_clicks();

		else if (this->event.type == sf::Event::TextEntered) //entering text
			for (auto &obj : Etext_box::etext_boxes)
				if (obj->active)
					obj->keyadded(event);
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
		if (obj->rectangle.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			obj->activate();
		else
			obj->deactivate();
	}

	for (auto &obj : Eclickable::eclickables)
	{
		if (obj->rectangle.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			obj->activate();
	}
}

void Ewindow::release_clicks()
{
	for (auto &obj : Eclickable::eclickables)
	{
		obj->deactivate();
	}
}