#pragma once
#include "../component.h"
#include "../window.h"
#include "components/text_box.h"

#define cv2f const sf::Vector2f


class Ewindow;

class Ebutton : public Eclickable
{
	sf::Text text;
	Ewindow *window_parent;

public:
	void deactivate();
	Ebutton(cv2f &pos, cv2f &size, const sf::String &text_str, int, std::function<void(Ewindow *)> on_click);
	Ebutton(cv2f &pos, cv2f &size, const sf::String &text_str, int, std::function<void(Ewindow *)> on_click, Ewindow *);
	~Ebutton();
	std::function<void(Ewindow *)> on_click;
	void set_up(cv2f &pos, cv2f &size, const sf::String &text_str, int, std::function<void(Ewindow *)> on_click);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
