#include "../../include/components/graph_box.h"

Egraph_box::Egraph_box(const sf::Vector2f &pos, const sf::Vector2f &size)
{
	this->active = true;
	this->color_deactive = sf::Color(44, 56, 62);
	this->color_active = sf::Color(54, 66, 72);
	this->position = pos;

	this->rectangle.setFillColor(sf::Color::Black);
	this->rectangle.setPosition(position);
	this->rectangle.setSize(size);
	this->drawable.create((int)size.x, (int)size.y);

	this->esprite.setTexture(drawable.getTexture());
	this->esprite.setPosition(pos);

	construct_lines();
	drawable.draw(lineX);
	drawable.draw(lineY);
	drawable.display();

	update();
}

void Egraph_box::update() //have to be used later in draw method
{
	esprite.setTexture(this->drawable.getTexture());
}

void Egraph_box::clear()
{
	drawable.clear();
	drawable.draw(lineX);
	drawable.draw(lineY);
	drawable.display();
	update();
}

void Egraph_box::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
	target.draw(esprite);
}
void Egraph_box::draw_lines(const sf::Vector2f first, const sf::Vector2f second)
{
	line[0].position = first;
	line[1].position = second;
	drawable.draw(line, 2, sf::Lines);
	drawable.display();
}
void Egraph_box::construct_lines()
{
	this->lineY.setFillColor(sf::Color(255, 255, 255));
	this->lineY.setPosition(sf::Vector2f(rectangle.getGlobalBounds().width / 2 - 1, 0)); //width of axix breaks precision
	this->lineY.setSize(sf::Vector2f(3, rectangle.getGlobalBounds().height));

	this->lineX.setFillColor(sf::Color(255, 255, 255));
	this->lineX.setPosition(sf::Vector2f(0, rectangle.getGlobalBounds().height / 2 - 1)); //need to be fixed
	this->lineX.setSize(sf::Vector2f(rectangle.getGlobalBounds().width, 3));

	line[0].color = sf::Color::White;
	line[1].color = sf::Color::White;
}