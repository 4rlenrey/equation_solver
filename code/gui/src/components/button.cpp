#include "../../include/components/button.h"

sf::Font Efonts::basic;

Ebutton::Ebutton(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::String &text_str, int c_size, std::function<void(Ewindow *)> on_click)
{
	set_up(pos, size, text_str, c_size, on_click);
	window_parent = NULL;
}

Ebutton::Ebutton(const sf::Vector2f &pos, const sf::Vector2f &size, const sf::String &text_str, int c_size, std::function<void(Ewindow *)> on_click, Ewindow *t)
{
	set_up(pos, size, text_str, c_size, on_click);
	window_parent = t;
}
Ebutton::~Ebutton()
{
	window_parent = NULL;
}
void Ebutton::set_up(const sf::Vector2f &position, const sf::Vector2f &size, const sf::String &text_str, int c_size, std::function<void(Ewindow *)> on_click)
{
	active = false;
	color_deactive = sf::Color(44, 56, 62);
	color_active = sf::Color(54, 66, 72);
	this->position = position;

	rectangle.setFillColor(color_deactive);
	rectangle.setPosition(position);
	rectangle.setSize(size);


	text.setString(text_str);
	text.setFont(Efonts::basic);
	text.setCharacterSize(c_size);

	text_position.x = position.x + (size.x - text.getLocalBounds().width)/2;
	text_position.y = position.y + (size.y - text.getLocalBounds().height)/2;
	text.setPosition(text_position);
	text.setFillColor(sf::Color(244, 244, 249));

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
		on_click(window_parent);
	}
}