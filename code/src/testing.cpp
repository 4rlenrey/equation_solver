#include "../include/testing.h"

#define TEST_CONTAINER std::vector<std::pair<std::string, std::string>> test_cases
#define ADD_TEST_CASE test_cases.push_back
#define PAIR std::make_pair
#define ALL_TESTS for (int i = 0; i < test_cases.size(); i++)

bool Etesting::base()
{
		
	std::string a_numbers = "01234567890,.x";
	std::unordered_set<char> numbers;

	for (const char &i : a_numbers)
		numbers.insert(i);

	bool passed = true;

	TEST_CONTAINER;

	ADD_TEST_CASE(PAIR("2+2", "4"));
	ADD_TEST_CASE(PAIR("2/2", "1"));
	ADD_TEST_CASE(PAIR("5-2", "3"));
	ADD_TEST_CASE(PAIR("2*(3*3)-3", "15"));
	ADD_TEST_CASE(PAIR("2+5-2-5", "0"));
	ADD_TEST_CASE(PAIR("3*5+5*(3-2)", "20"));
	ADD_TEST_CASE(PAIR("4*x/2*x", "2"));

	ALL_TESTS
	{
		std::string sss = Esolve::main(test_cases[i].first, 1, numbers);

		if (sss != test_cases[i].second)
		{
			std::cout << "Test #" << i << " Failed! \n";
			std::cout << sss << " != " << test_cases[i].second << "\n";
		}
		else
		{
			std::cout << "Test #" << i << " Passed! \n";
		}
	}

	//Etesting::bracket();

	return passed;
}

bool Etesting::bracket()
{
	bool passed = true;
	TEST_CONTAINER;

	ADD_TEST_CASE(PAIR("((3(4)3(3423)))", "13"));
	ADD_TEST_CASE(PAIR("((()()(())()()))()()()", "14"));

	ALL_TESTS
	{
		if (std::to_string(Ecore::get_ending_bracket(test_cases[i].first, 1)) != test_cases[i].second)
		{
			std::cout << "Bracket Test #" << i << " Failed! ";
			std::cout << std::to_string(Ecore::get_ending_bracket(test_cases[i].first, 1)) << " != " << test_cases[i].second << "\n";
		}
		else
			std::cout << "Bracket Test #" << i << " Passed! \n";
	}
	return passed;
}
