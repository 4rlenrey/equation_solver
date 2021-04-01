#include"../include/core.h"

bool Ecore::run(std::pair<int, int> range, std::string equation)
{
	if (Evalidate::equation(equation))
	{
		std::cout << "Valid equation"
				  << "\n";
		std::string fixed_equation = Evalidate::simplify(equation);
		std::cout << "Fixed equation is: " << fixed_equation << "\n";

		std::string output;
		//for first few points
		for (int x = range.first; x <= range.second; x++)
		{
			try
			{
				output = Ecore::main_solve(fixed_equation, x);
				std::cout << "x = " << x << " y = " << output << "\n";
			}
			catch (const std::exception &e)
			{
				std::cerr << "There's an error caused by: " << e.what() << '\n';
			}
		}
	}

	return 0;
}

std::string Ecore::main_solve(const std::string &str, int x)
{
	std::string s = str;
	std::string a_numbers = "01234567890,.x";
	std::string a_operations = "*^/-+";
	std::unordered_set<char> number;
	std::unordered_set<char> operation;

	for (const char &i : a_numbers)
		number.insert(i);
	for (const char &i : a_operations)
		operation.insert(i);

	std::string s_x = std::to_string(x);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'x')
		{
			s.erase(i, 1);
			s.insert(i, s_x);
		}
	}
	return Ecore::solve_simple(s, number, operation);
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
std::pair<std::pair<double, double>, std::pair<int, int>> Ecore::getnumbers(const std::string &s, int i, std::unordered_set<char> &numbers, std::unordered_set<char> &operators)
{
	//getting the number
	int start_num = 0;
	int koniec_num = i;

	for (int j = i - 1; j >= 0; j--)
	{

		if (numbers.find(s[j]) == numbers.end())
		{
			start_num = j + 1;
			break;
		}
	}
	if (start_num > 0)
	{
		if (s[start_num - 1] == '-')
		{
			start_num--;
		}
	}
	std::string s_first_d = s.substr(start_num, koniec_num);

	int replace_index_start = start_num; //replace starts with the left number

	start_num = i + 1;
	koniec_num = s.size();

	if (s[i + 1] == '-')
	{
		i++;
	}
	for (int j = i + 1; j <= s.size(); j++)
	{
		if (numbers.find(s[j]) == numbers.end())
		{
			koniec_num = j + 1;
			break;
		}
	}
	std::string s_second_d = s.substr(start_num, koniec_num);

	double first = std::stod(s_first_d);
	double second = std::stod(s_second_d);

	int replace_index_end = koniec_num; //replace ends with the right number
	return std::make_pair(std::make_pair(first, second), std::make_pair(replace_index_start, replace_index_end));
}

std::string Ecore::solve_simple(const std::string &str, std::unordered_set<char> &numbers, std::unordered_set<char> &operators)
{
	std::vector<char> operations_av = {'^', '*', '/', '+', '-'};
	std::string s = str;

	for (int i = 0; i < s.size(); i++) //recursion for all the (())(())
	{
		if (s[i] == '(')
		{
			int until_brac = Ecore::get_ending_bracket(s, i) - i;
			std::string s_substr = s.substr(i + 1, until_brac - 1);
			std::string result = Ecore::solve_simple(s_substr, numbers, operators);
			if (result == "NO")
				return result;
			else
				s.replace(i, until_brac + 1, result);
		}
	}

	for (const char operat : operations_av)
	{
		for (int i = 1; i < s.size(); i++)
		{

			if (s[i] == operat)
			{
				long long int result = 1;
				std::pair<std::pair<double, double>, std::pair<int, int>> packet = Ecore::getnumbers(s, i, numbers, operators);
				//might be changed to something more precise
				//operations order be gut

				switch (operat)
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
				i = packet.second.first;
				//std::cout << "Operation: " << operat << " Numbers: " << packet.first.first << " " << packet.first.second << "\n";
			}
		}
	}
	return s;
}