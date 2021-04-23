#pragma once

#include <iostream>
#include <unordered_set>
#include <vector>
#include <list>
#include <thread>

#include "validate.h"


namespace Ecore
{
	int get_ending_bracket(const std::string &, int start);
	std::pair<std::pair<double, double>, std::pair<int, int>> getnumbers(const std::string &, int start, const std::unordered_set<char> &numbers);
}

namespace Esolve
{
	std::string main(std::string, int, const std::unordered_set<char> &);
	std::string partly(std::string, const std::unordered_set<char> &);
}

namespace Eget_set
{
	std::vector<std::string> main(std::string equation, const std::pair<int, int> &range, int &threads, const std::unordered_set<char> &se);
	void fill_vector(std::vector<std::string> &v,  std::string equation, const int start, int end, int x,std::unordered_set<char> se);
}
