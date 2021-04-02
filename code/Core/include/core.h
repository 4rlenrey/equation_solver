#pragma once

#include <iostream>
#include <unordered_set>
#include <vector>
#include "validate.h"


namespace Ecore{
	bool run(std::pair<int, int> range, std::string equation);
	int get_ending_bracket(const std::string&, int start);
	std::pair<std::pair<double, double>,std::pair<int, int>> getnumbers(const std::string&, int start, std::unordered_set<char> &numbers);
}

namespace Esolve{
	std::string main(std::string, int);
	std::string partly(std::string, std::unordered_set<char>&);
}