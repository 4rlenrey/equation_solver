#include "../../include/components/button.h"

sf::Font Efonts::basic;

Ebutton::Ebutton(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::String &text_str, int c_size, std::function<void( Etext_box*)> on_click)
{
	set_up(pos, size, text_str, c_size, on_click);
	text_source = NULL;
}

Ebutton::Ebutton(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::String &text_str, int c_size, std::function<void( Etext_box*)> on_click,  Etext_box *t)
{
	set_up(pos, size, text_str, c_size, on_click);
	text_source = t;
}
Ebutton::~Ebutton()
{
	text_source = NULL;
}
void Ebutton::set_up(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::String &text_str, int c_size, std::function<void( Etext_box*)> on_click)
{
	this->text.setString(text_str);
	this->text.setFont(Efonts::basic);
	this->text.setCharacterSize(c_size);
	this->text.setPosition(pos);
	this->text.setFillColor(sf::Color(244, 244, 249));

	this->active = false;
	this->color_deactive = sf::Color(44, 56, 62);
	this->color_active = sf::Color(54, 66, 72);
	this->position = pos;

	this->rectangle.setFillColor(color_deactive);
	this->rectangle.setPosition(position);
	this->rectangle.setSize(size);

	this->on_click = on_click;
}

void Ebutton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
	target.draw(text, states);
}

void Ebutton::deactivate()
{
	if (active)
	{
		rectangle.setFillColor(color_deactive);
		active = false;
	}
	on_click(text_source);
}