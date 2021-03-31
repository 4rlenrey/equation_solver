#pragma once

#include <iostream>
#include <unordered_set>
#include <vector>

namespace Ecore{
	std::string get_input();
	bool run();
	std::string main_solve(const std::string&, int x);
	std::string solve_simple(const std::string&, std::unordered_set<char>& numbers, std::unordered_set<char>& operators);
	int get_ending_bracket(const std::string&, int start);
	std::pair<std::pair<double, double>,std::pair<int, int>> getnumbers(const std::string&, int start, std::unordered_set<char> &numbers, std::unordered_set<char> &operators);
}
