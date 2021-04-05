#pragma once
#include "static_assets.h"

class Ecomponent : public sf::Drawable
{
public:
	Ecomponent();

	bool active;
	sf::RectangleShape rectangle;
	sf::Color color_active;
	sf::Color color_deactive;
	sf::Vector2f position;


	static std::vector<Ecomponent *> ecomponents;
	void add_to_vector();

	virtual void activate();
	virtual void deactivate();
	virtual ~Ecomponent();
};

class Eclickable : public Ecomponent
{
public:
	Eclickable();

	static std::vector<Eclickable *> eclickables;

	virtual ~Eclickable();
};

class Efocusable : public Ecomponent
{
public:
	Efocusable();
	static std::vector<Efocusable *> efocusables;

	void update();
	virtual ~Efocusable();
};