#include "../include/core.h"


int Ecore::get_ending_bracket(const std::string &s, int start)
{
	unsigned long int i = start + 1;
	int indention_level = 1;
	while (i <= s.size())
	{
		switch (s[i])
		{
		case '(':
			indention_level++;
			break;

		case ')':
			indention_level--;
			break;
		default:
			break;
		}
		if (indention_level == 0)
			return i;
		i++;
	}
	return 0;
}

//first number, second number, start (to replace), end (to replace)
std::pair<std::pair<double, double>, std::pair<int, int>> Ecore::getnumbers(const std::string &s, int i, std::unordered_set<char> &numbers)
{
	int i_start = 0; //variables helping to get the numbers
	int i_end = i;

	for (int j = i - 1; j >= 0; j--)
	{

		if (numbers.find(s[j]) == numbers.end())
		{
			i_start = j + 1;
			break;
		}
	}
	if (i_start > 0)
	{
		if (s[i_start - 1] == '-')
		{
			i_start--;
		}
	}
	std::string first_number = s.substr(i_start, i_end);

	int replace_index_start = i_start; //replace starts with the start of a left number

	i_start = i + 1;
	i_end = s.size();

	if (s[i + 1] == '-') //if second numbers is negative then '-' should be a part of a number
	{
		i++;
	}
	for (int j = i + 1; j <= s.size(); j++)
	{
		if (numbers.find(s[j]) == numbers.end())
		{
			i_end = j + 1;
			break;
		}
	}
	std::string second_number = s.substr(i_start, i_end);
	double double_first_number;
	double double_second_number;
	try
	{
		double_first_number = std::stod(first_number);
		double_second_number = std::stod(second_number);
	}
	catch (const std::exception &e)
	{
		std::cerr << "An error has occured by " << e.what() << "while trying to convert these numbers to double type: ";
		std::cerr << first_number << " " << second_number << "\n";
		return std::make_pair(std::make_pair(0, 0), std::make_pair(-1, -1));
	}

	int replace_index_end = i_end; //replace ends with the right number
	return std::make_pair(std::make_pair(double_first_number, double_second_number), std::make_pair(replace_index_start, replace_index_end));
}
