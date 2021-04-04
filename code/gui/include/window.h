#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Ewindow
{
	sf::RenderWindow window;

public:
	Ewindow(int size_x, int size_y, std::string title);
	void run();
};
