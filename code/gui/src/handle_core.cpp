#include "../include/window.h"

void Ehandle_core::draw_funct(Ewindow *w)
{

	Etext_box *b = w->equation_box;
	Egraph_box *gb = w->graph_box;
	std::string equation = b->get_text();

	std::cout << equation
			  << "\n";

	std::pair<int, int> range;
	range.first = -400;
	range.second = 400;

	std::string a_numbers = "01234567890,.x";
	std::unordered_set<char> numbers;

	for (const char &i : a_numbers)
		numbers.insert(i);

	if (Evalidate::equation(equation))
	{
		std::string fixed_equation = Evalidate::simplify(equation);

		int threads_count = 1; //will be changed later

		std::vector<std::string> numbers_start = Eget_set::main(fixed_equation, range, threads_count, numbers);

		bool before = false;
		const int y_ax = gb->lineX.getGlobalBounds().top;
		int beforeY = 0;
		int beforeX = 0;
		int nowY = 0;
		int nowX = 0;

		for (const auto &i : numbers_start)
		{
			nowX++; //can be later changed to another precision

			if (i[1] == '#')
			{
				before = false;
			}
			else
			{
				try
				{
					nowY = stoi(i);
					if (before)
					{
						gb->draw_lines(sf::Vector2f(beforeX, (y_ax - beforeY)), sf::Vector2f(nowX, (y_ax - nowY)));
						beforeY = nowY;
						beforeX = nowX;
					}
					else
					{
						beforeY = nowY;
						beforeX = nowX;
					}
					before = true;
				}
				catch (const std::exception &e)
				{
					std::cerr << e.what() << '\n';
					before = false;
				}
			}
		}
	}
	gb->update();
}