#pragma once
#include "../Core/include/core.h"

class Eapplication
{
	std::string mode;
	std::string equation;
	std::pair<int, int> range;
	void tui();
	void gui();

public:
	Eapplication(std::string mode);
	void run();
};