#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

class Ecomponent : public sf::Drawable
{
public:
	Ecomponent();

	static std::vector<Ecomponent *> ecomponents;
	void add_to_vector();

	virtual ~Ecomponent();
};

class Efocusable : public Ecomponent
{
public:
	Efocusable();

	static std::vector<Efocusable *> efocusables;

	bool active;
	sf::RectangleShape rectangle;
	sf::Color color_active;
	sf::Color color_deactive;
	sf::Vector2f position;

	virtual void activate();
	virtual void deactivate();

	virtual ~Efocusable();
};