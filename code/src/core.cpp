#include<iostream>
#include"../include/core.h"
#include"../include/input.h"

std::string Ecore::get_input(){
	std::string Estring;
	std::cin >> Estring;
	return Estring;
}

bool Ecore::run()
{
	std::string equation = Ecore::get_input();
	if(Einput::validate(equation))
	{
		std::cout << "Valid equation" << "\n";
	}
		
	return 0;
}
