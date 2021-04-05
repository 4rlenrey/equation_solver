#include "../../include/components/button.h"

sf::Font Efonts::basic;

Ebutton::Ebutton(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::String &text_str, int c_size)
{
	this->text.setString(text_str);
	this->text.setFont(Efonts::basic);
	this->text.setCharacterSize(c_size);
	this->text.setPosition(sf::Vector2f(0, 0));
	this->text.setFillColor(sf::Color(244, 244, 249));

	this->active = false;
	this->color_deactive = sf::Color(44, 56, 62);
	this->color_active = sf::Color(54, 66, 72);
	this->position = pos;

	this->rectangle.setFillColor(color_deactive);
	this->rectangle.setPosition(position);
	this->rectangle.setSize(size);
}


void Ebutton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
	target.draw(text, states);
}
