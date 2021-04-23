#include "../include/window.h"


void Ehandle_core::draw_funct(Ewindow *);
void Ehandle_core::clearwindow(Ewindow *);

Ewindow::Ewindow(int size_x, int size_y, std::string title)
{
	window.create(sf::VideoMode(size_x, size_y), title);

	equation_box = new Etext_box(sf::Vector2f(200, 600), sf::Vector2f(350, 100), 20);
	threads_count_box = new Etext_box(sf::Vector2f(600, 600), sf::Vector2f(100, 100), 20);
	accuracy_box = new Etext_box(sf::Vector2f(750, 600), sf::Vector2f(100, 100), 20);

	confirm_equation = new Ebutton(sf::Vector2f(50, 600), sf::Vector2f(100, 100), "Generate", 20, Ehandle_core::draw_funct, this);
	clear_button = new Ebutton(sf::Vector2f(50, 720), sf::Vector2f(100, 50), "Clear", 20, Ehandle_core::clearwindow, this);
	graph_box = new Egraph_box(sf::Vector2f(50, 50), sf::Vector2f(801, 501));

	background.setFillColor(sf::Color(184, 219, 217));
	background.setPosition(sf::Vector2f(0, 0));
	background.setSize(sf::Vector2f(size_x, size_y));

	run();
}
Ewindow::~Ewindow()
{
	delete this->confirm_equation;
	delete this->clear_button;
	delete this->equation_box;
	delete this->threads_count_box;
	delete this->accuracy_box;
	delete this->graph_box;
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
	this->window.draw(background);
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