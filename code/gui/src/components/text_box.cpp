#include "../../include/components/text_box.h"

std::vector<Etext_box *> Etext_box::etext_boxes;

Etext_box::Etext_box(const sf::Vector2f &pos, const sf::Vector2f &size, int c_size)
{
	this->position = pos;
	this->active = false;

	this->text.setFont(Efonts::basic);
	this->text.setCharacterSize(c_size);
	this->text.setPosition(position);
	this->text.setFillColor(sf::Color(244, 244, 249));

	this->color_deactive = sf::Color(44, 56, 62);
	this->color_active = sf::Color(54, 66, 72);

	this->rectangle.setFillColor(color_deactive);
	this->rectangle.setPosition(position);
	this->rectangle.setSize(size);

	this->coursor_ef = sf::Time::Zero;
	this->show_cursor = false;
	etext_boxes.push_back(this);
}

void Etext_box::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
	target.draw(text, states);
}

void Etext_box::update()
{
	coursor_ef += clock.restart();
	if (coursor_ef >= sf::seconds(0.5f))
	{
		show_cursor = !show_cursor;
		coursor_ef = sf::Time::Zero;
	}
	text.setString(input_text + (show_cursor ? '_' : ' '));
}

Etext_box::~Etext_box()
{
	etext_boxes.erase(std::remove(begin(etext_boxes), end(etext_boxes), this), end(etext_boxes));
}

void Etext_box::keyadded(sf::Event event)
{
	if (std::isprint(event.text.unicode))
	{
		input_text += event.text.unicode;
	}
	else if (event.text.unicode == 8)
		if (!input_text.empty())
			input_text.pop_back();
}
