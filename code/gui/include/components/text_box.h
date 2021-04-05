#pragma once
#include "../component.h"

class Etext_box : public Efocusable
{
	sf::Text text;
public:
	
	Etext_box(const sf::Vector2f &pos, const sf::Vector2f &size, int);
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	static sf::Font font;

};
