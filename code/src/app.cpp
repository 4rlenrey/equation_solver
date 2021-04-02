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
	Evalidate::range(this->range);
	std::cout << "Your x range is from " << this->range.first << " to " << this->range.second << "\n";
	
	if (Evalidate::equation(equation))
	{
		std::string fixed_equation = Evalidate::simplify(equation);

		for (int x = range.first; x <= range.second; x++) //solves all points in range
		{
			try
			{
				std::cout << "x = " << x << " y = " << Esolve::main(fixed_equation, x) << "\n";
			}
			catch (const std::exception &e)
			{
				std::cerr << "There's an error caused by: " << e.what() << '\n';
			}
		}
	}
	
}