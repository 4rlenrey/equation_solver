#pragma once
#include "../component.h"

#define cv2f const sf::Vector2f

class Egraph_box : public Ecomponent
{
	sf::RenderTexture drawable;
	sf::Sprite esprite;
	sf::RectangleShape lineY;
	sf::RectangleShape lineX;

public:
	Egraph_box(cv2f &pos, cv2f &size);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void update();
	void draw_lines();
	void construct_lines();
	void draw_equation(std::vector<std::string>);
};
