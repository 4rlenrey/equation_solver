#include "../include/core.h"

std::string Esolve::main(std::string s, int x, const std::unordered_set<char> &numbers)
{
	std::string s_x = std::to_string(x);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'x')
		{
			s.replace(i, 1, s_x);
		}
	}
	return Esolve::partly(s, numbers);
}

std::string Esolve::partly(std::string s,const std::unordered_set<char> &numbers)
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