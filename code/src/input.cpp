#include <iostream>
#include <unordered_set>
#include "../include/input.h"

bool Einput::validate_brackets(const std::string &s)
{
	unsigned long int i = 0;
	int indention_level = 0;
	while (i < s.size())
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
		if (indention_level < 0)
			return 0;
		i++;
	}

	if (indention_level != 0)
		return 0;

	return 1;
}

bool Einput::validate_characters(const std::string &s)
{
	std::string allowed_ch = "123456789,.()*^-+x"; //allowed characters //later need to add %!
	std::unordered_set<char> allowed;
	for (const char &i : allowed_ch)
	{ //parse all allowed characters to set
		allowed.insert(i);
	}
	for (const char &i : s)
	{
		if (allowed.find(i) == allowed.end())
		{ //check if all characters from equations are in set
			return 0;
		}
	}
	return 1;
}

bool Einput::validate(const std::string &s)
{
	unsigned short int lenght = s.length();
	if (lenght == 0)
	{ //size must be bigger than 0
		std::cerr << "Error! "
				  << "Can't validate size"
				  << "\n";
		return 0;
	}
	if (!Einput::validate_brackets(s))
	{
		std::cerr << "Error! "
				  << "Can't validate brackets"
				  << "\n";
		return 0;
	}
	if (!Einput::validate_characters(s))
	{
		std::cerr << "Error! "
				  << "Can't validate characters"
				  << "\n";
		return 0;
	}

	return 1;
}
bool Einput::fix_brackets(std::string &s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' && s[i + 1] == ')')
		{
			s.erase(i, 2);
			//improve later
			i = -1;
		}
	}
	return 1;
}

std::string Einput::simplify(const std::string &str)
{
	std::string s = str;

	std::string a_numbers = "123456789,.x";
	std::string a_operations = "*^-+";
	std::unordered_set<char> number;
	std::unordered_set<char> operation;

	for (const char &i : a_numbers)
		number.insert(i);
	for (const char &i : a_operations)
		operation.insert(i);

	if (Einput::fix_brackets(s))
	{
		std::cout << "Fixed brackets succesfully \n";
	}

	for (int i = 0; i < s.size(); i++)
	{

		//3x -----> 3*x
		if (number.find(s[i]) != number.end()) //if a number
			if (s[i + 1] == 'x')
				s.insert(i + 1, "*");
			else if (s[i + 1] == '-' && s[i + 2] == 'x')
				s.insert(i + 1, "*");
		//(2+1)2 ------> (2+1)*2
		if (s[i] == ')' && number.find(s[i + 1]) != number.end())
			s.insert(i + 1, "*");

		//2(2+1) ------> 2(2+1)
		if (s[i + 1] == '(' && number.find(s[i]) != number.end())
			s.insert(i + 1, "*");
	}
	return s;
}