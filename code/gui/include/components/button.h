#pragma once
#include "../component.h"

#define cv2f const sf::Vector2f

class Ebutton : public Eclickable
{
	sf::Text text;

public:
	void deactivate();
	Ebutton(cv2f &pos, cv2f &size, const sf::String &text_str, int, std::function<void(void)> on_click);
	std::function<void(void)> on_click;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
