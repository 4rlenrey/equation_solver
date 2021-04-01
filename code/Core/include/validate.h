#pragma once

#include <iostream>
#include <unordered_set>
#include <string>
#include <cmath>
#include "../include/core.h"

namespace Evalidate{
	bool equation(const std::string&);
	bool brackets(const std::string&);
	bool characters(const std::string&);
	std::string simplify(const std::string&);
	bool fix_brackets(std::string&);
}