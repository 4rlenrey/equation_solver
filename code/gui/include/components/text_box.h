#pragma once
#include "../component.h"

class Etext_box : public Efocusable
{
	sf::Text text;
	std::string input_text;
	sf::Clock clock;
	bool show_cursor;
	sf::Time coursor_ef;
public:
	void update();
	void keyadded(sf::Event);

	static std::vector<Etext_box *> etext_boxes;

	Etext_box(const sf::Vector2f &pos, const sf::Vector2f &size, int);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	virtual ~Etext_box();
};
