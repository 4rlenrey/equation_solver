#pragma once
#include "../component.h"

#define cv2f const sf::Vector2f



class Elabel : public Ecomponent
{
	sf::Text text;

public:
	Elabel(cv2f pos, int size, sf::String);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	~Elabel();
};
