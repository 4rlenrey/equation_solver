#include <iostream>
#include <unordered_set>
#include <string>
#include <cmath>
#include "../include/core.h"
#include "../include/input.h"

std::string Ecore::get_input()
{
	std::string Estring;
	std::cin >> Estring;
	return Estring;
}

bool Ecore::run()
{
	std::string equation = Ecore::get_input();
	if (Einput::validate(equation))
	{
		std::cout << "Valid equation"
				  << "\n";
		std::string fixed_equation = Einput::simplify(equation);
		std::cout << "Fixed equation is: " << fixed_equation << "\n";
		std::cout << "For x = 1 y = " << Ecore::main_solve(fixed_equation, 1) <<"\n";
		std::cout << "For x = 2 y = " << Ecore::main_solve(fixed_equation, 2) <<"\n";
		std::cout << "For x = 3 y = " << Ecore::main_solve(fixed_equation, 3) <<"\n";
	}

	return 0;
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
	std::string s_first_d = s.substr(start_num, koniec_num);

	int replace_index_start = start_num; //replace starts with the left number

	start_num = i + 1;
	koniec_num = s.size();

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

double Ecore::solve_simple(const std::string &str, std::unordered_set<char> &numbers, std::unordered_set<char> &operators)
{
	std::string s = str;

	for (int i = 0; i < s.size(); i++) //recursion for all the (())(())
	{
		if (s[i] == '(')
		{
			std::string s_substr = s.substr(i+1, (Ecore::get_ending_bracket(s, i)-3));
			int result = (int)Ecore::solve_simple(s_substr, numbers, operators);
			std::string s_result = std::to_string(result);
			int until_brac = Ecore::get_ending_bracket(s, i) - i;
			s.erase(i, until_brac+1);
			s.insert(i, s_result);
		}
	}
	//pow is first
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '^')
		{
			std::pair<std::pair<double, double>, std::pair<int, int>> packet = Ecore::getnumbers(s, i, numbers, operators);
			//might be changed to something more precise
			int result = (int)std::round(pow(packet.first.first, packet.first.second));

			s.erase(packet.second.first, (packet.second.second - packet.second.first));
			s.insert(packet.second.first, std::to_string(result));
		}
	}
	//dividing multipliing second
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*')
		{
			std::pair<std::pair<double, double>, std::pair<int, int>> packet = Ecore::getnumbers(s, i, numbers, operators);
			//might be changed to something more precise
			int result = (int)std::round(packet.first.first * packet.first.second);

			s.erase(packet.second.first, (packet.second.second - packet.second.first));
			s.insert(packet.second.first, std::to_string(result));
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '/')
		{
			std::pair<std::pair<double, double>, std::pair<int, int>> packet = Ecore::getnumbers(s, i, numbers, operators);
			//might be changed to something more precise
			int result = (int)std::round(packet.first.first / packet.first.second);

			s.erase(packet.second.first, (packet.second.second - packet.second.first));
			s.insert(packet.second.first, std::to_string(result));
		}
	}
	//adding substracting last
	//dividing multipliing second
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '+')
		{
			std::pair<std::pair<double, double>, std::pair<int, int>> packet = Ecore::getnumbers(s, i, numbers, operators);
			//might be changed to something more precise
			int result = (int)std::round(packet.first.first + packet.first.second);

			s.erase(packet.second.first, (packet.second.second - packet.second.first));
			s.insert(packet.second.first, std::to_string(result));
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-')
		{
			std::pair<std::pair<double, double>, std::pair<int, int>> packet = Ecore::getnumbers(s, i, numbers, operators);
			//might be changed to something more precise
			int result = (int)std::round(packet.first.first - packet.first.second);

			s.erase(packet.second.first, (packet.second.second - packet.second.first));
			s.insert(packet.second.first, std::to_string(result));
		}
	}
	return std::stod(s);
}

double Ecore::main_solve(const std::string &str, int x)
{
	std::string s = str;
	std::string a_numbers = "123456789,.x-";
	std::string a_operations = "*^-+";
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
	std::cout << "After substituting x: ";
	std::cout << s << "\n";

	return Ecore::solve_simple(s, number, operation);
}