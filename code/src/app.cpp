#include "../include/app.h"
#include <SFML/Graphics.hpp>

Eapplication::Eapplication(std::string mode)
{
	this->mode = mode;
}

void Eapplication::run()
{
	if (this->mode == "TUI")
	{
		tui();
	}
	else if (this->mode == "GUI")
	{
		gui();
	}
}

void Eapplication::gui()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}

void Eapplication::tui()
{
	std::cout << "Welcome to Equalizatinator \n";
	std::cout << "Enter your equation: ";
	std::cin >> this->equation;
	std::cout << "Your equation is: " << this->equation << "\n";
	std::cout << "Enter starting x: ";
	std::cin >> this->range.first;
	std::cout << "Enter ending x: ";
	std::cin >> this->range.second;
	Evalidate::range(this->range);
	std::cout << "Your x range is from " << this->range.first << " to " << this->range.second << "\n";

	std::string a_numbers = "01234567890,.x";
	std::unordered_set<char> numbers;

	for (const char &i : a_numbers)
		numbers.insert(i);

	if (Evalidate::equation(equation))
	{
		std::string fixed_equation = Evalidate::simplify(equation);
		int threads_count;
		std::cout << "How many threads do you want to use(1-5): ";
		std::cin >> threads_count;

		std::vector<std::string> numbers_start = Eget_set::main(fixed_equation, this->range, threads_count, numbers);

		int x = range.first;
		for (const auto &i : numbers_start)
		{
			std::cout << "x = " << x << " y = " << i << "\n";
			x++;
		}
	}
}