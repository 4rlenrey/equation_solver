#include "../../include/components/button.h"

sf::Font Ebutton::font;

Ebutton::Ebutton(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::String &text_str, int c_size)
{
	this->text.setString(text_str);
	this->text.setFont(font);
	this->text.setCharacterSize(c_size);
	this->text.setPosition(sf::Vector2f((pos.x + size.x/2),(pos.y + size.y/2)));
	this->text.setFillColor(sf::Color(244, 244, 249));

	this->rectangle.setFillColor(sf::Color(44, 56, 62));
	this->rectangle.setPosition(pos);
	this->rectangle.setSize(size);
}


void Ebutton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
	target.draw(text, states);
}