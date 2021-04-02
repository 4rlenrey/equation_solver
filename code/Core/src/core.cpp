#include "../include/core.h"

//need to add:
//!
//%


bool Ecore::run(std::pair<int, int> range, std::string equation)
{
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

	return 0;
}

std::string Esolve::main(std::string s, int x)
{
	std::string a_numbers = "01234567890,.x";
	std::unordered_set<char> numbers;

	for (const char &i : a_numbers)
		numbers.insert(i);

	std::string s_x = std::to_string(x);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'x')
		{
			s.replace(i, 1, s_x);
			s.insert(i, s_x);
		}
	}
	return Esolve::partly(s, numbers);
}

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

std::string Esolve::partly(std::string s, std::unordered_set<char> &numbers)
{
	std::vector<char> operations_av = {'^', '*', '/', '+', '-'};

	for (int i = 0; i < s.size(); i++) //recursion for all the (())(())
	{
		if (s[i] == '(')
		{
			int until_brac = Ecore::get_ending_bracket(s, i) - i;
			std::string result = Esolve::partly(s.substr(i + 1, until_brac - 1), numbers);
			if (result[0] == '#')
				return result;
			else
				s.replace(i, until_brac + 1, result);
		}
	}

	for (const char operation : operations_av) //does all the operations
	{
		for (int i = 1; i < s.size(); i++)
		{

			if (s[i] == operation)
			{
				long long int result = 1;

				//get numbers and replace indexes
				std::pair<std::pair<double, double>, std::pair<int, int>> packet = Ecore::getnumbers(s, i, numbers);
				//if getnumbers failed then it should return error
				if (packet.second.first == -1)
					return "#1";

				switch (operation)
				{
				case '^':
					result = (long long int)(pow(packet.first.first, packet.first.second));
					break;
				case '*':
					result = (long long int)(packet.first.first * packet.first.second);
					break;
				case '/':
					if (s[i + 1] == '0')
						return "#0"; //cant divide by zero
					else
						result = (long long int)(packet.first.first / packet.first.second);
					break;
				case '+':
					result = (long long int)(packet.first.first + packet.first.second);
					break;
				case '-':
					result = (long long int)(packet.first.first - packet.first.second);
					break;
				default:
					break;
				}

				s.replace(packet.second.first, (packet.second.second - packet.second.first) - 1, std::to_string(result));
				i = packet.second.first; //index should go back to where the operation has occured
			}
		}
	}
	return s;
}