#include "../include/testing.h"

#define ADD_TEST_CASE test_cases.push_back
#define PAIR std::make_pair

bool Etesting::base()
{
	bool passed = true;
	std::vector<std::pair<std::string, std::string>> test_cases;

	ADD_TEST_CASE(PAIR("2+2", "4"));
	ADD_TEST_CASE(PAIR("2/2", "1"));
	ADD_TEST_CASE(PAIR("5-2", "3"));
	ADD_TEST_CASE(PAIR("2*(3*3)-3", "15"));
	ADD_TEST_CASE(PAIR("2+5-2-5", "0"));
	ADD_TEST_CASE(PAIR("3*5+5*(3-2)", "20"));


	for (int i = 0; i < test_cases.size(); i++)
	{
		if (Ecore::main_solve(test_cases[i].first, 1) != test_cases[i].second)
		{
			std::cout << "Test #" << i << " Failed! ";
			std::cout << Ecore::main_solve(test_cases[i].first, 1) << " != " << test_cases[i].second << "\n";
		}
		else
		{
			std::cout << "Test #" << i << " Passed! \n";
		}
	}

	return passed;
}
