#pragma once
#include "../component.h"

class Ebutton : public Ecomponent
{
	sf::Text text;
	sf::RectangleShape rectangle;
public:
	
	Ebutton(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::String &text_str, int);
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	static sf::Font font;

};