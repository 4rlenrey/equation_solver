#include "../../include/components/button.h"

sf::Font Ebutton::font;

Ebutton::Ebutton(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::String &text_str)
{
	this->text.setString(text_str);
	this->text.setFont(font);
	this->text.setCharacterSize(10);
	this->text.setPosition(sf::Vector2f(0, 0));
	this->text.setColor(sf::Color::Blue);

	this->rectangle.setFillColor(sf::Color::Yellow);
	this->rectangle.setPosition(pos);
	this->rectangle.setSize(size);
}


void Ebutton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
	target.draw(text, states);
}