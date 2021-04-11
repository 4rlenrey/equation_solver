#pragma once
#include "../component.h"
#include "text_box.h"

#define cv2f const sf::Vector2f

class Ebutton : public Eclickable
{
	sf::Text text;
	Etext_box* text_source;
public:
	void deactivate();
	Ebutton(cv2f &pos, cv2f &size, const sf::String &text_str, int, std::function<void(Etext_box*)> on_click);
	Ebutton(cv2f &pos, cv2f &size, const sf::String &text_str, int, std::function<void(Etext_box*)> on_click, Etext_box*);
	~Ebutton();
	std::function<void(Etext_box*)> on_click;
	void set_up(cv2f &pos, cv2f &size, const sf::String &text_str, int, std::function<void(Etext_box*)> on_click);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
