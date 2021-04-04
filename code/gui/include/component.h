#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

class Ecomponent : public sf::Drawable
{
public:
	Ecomponent();
	Ecomponent(const sf::Vector2f& pos, const sf::Vector2f& boxSize);

	static std::vector<Ecomponent *> ecomponents;
	void add_to_vector();

	virtual ~Ecomponent();
};