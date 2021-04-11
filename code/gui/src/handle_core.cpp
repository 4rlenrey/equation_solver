#include "../include/window.h"

void Ehandle_core::draw_funct(Etext_box *b)
{
	std::string equation = b->get_text();

	std::cout << equation
			  << "\n";

	std::pair<int, int> range;
	range.first = -10; 
	range.second = 10; 

	std::string a_numbers = "01234567890,.x";
	std::unordered_set<char> numbers;

	for (const char &i : a_numbers)
		numbers.insert(i);

	if (Evalidate::equation(equation))
	{
		std::string fixed_equation = Evalidate::simplify(equation);

		int threads_count = 1; //will be changed later

		std::vector<std::string> numbers_start = Eget_set::main(fixed_equation, range, threads_count, numbers);

		int x = range.first;
		for (const auto &i : numbers_start)
		{
			std::cout << "x = " << x << " y = " << i << "\n";
			x++;
		}
	}
}