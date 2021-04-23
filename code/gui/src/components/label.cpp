#include "../../include/components/label.h"


Elabel::Elabel(const sf::Vector2f pos, int size, sf::String label)
{
	text.setString(label);
	text.setFont(Efonts::basic);
	text.setCharacterSize(size);
	text.setPosition(pos);
	text.setFillColor(sf::Color::Black);
}

void Elabel::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(text, states);
}

Elabel::~Elabel(){}