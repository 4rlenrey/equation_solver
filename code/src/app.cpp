#include "../include/app.h"

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
	std::cout << "Your x range is from " << this->range.first << " to " << this->range.second << "\n";
	if(Ecore::run(this->range, this->equation))
	{
		std::cout << "Succesfully solved equation \n";
	}
}