#include<iostream>
#include<unordered_set>
#include"../include/input.h"

bool Einput::validate_brackets(const std::string& s){
	unsigned long int i = 0;
	int indention_level = 0;
	while(i < s.size())
	{
		switch(s[i])
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
		if(indention_level < 0)
			return 0;
		i++;
	}
	
	if(indention_level != 0)
		return 0;
	
	return 1;
}

bool Einput::validate_characters(const std::string& s){
	std::string allowed_ch = "123456789,.()*^-+%!x"; //allowed characters 
	std::unordered_set<char>allowed;
	for(const char& i : allowed_ch){ //parse all allowed characters to set
		allowed.insert(i);
	}
	for(const char& i : s){
		if(allowed.find(i) == allowed.end()){ //check if all characters from equations are in set
			return 0;
		}
	}
	return 1;
}

bool Einput::validate(const std::string& s){
	unsigned short int lenght = s.length();
	if(lenght == 0){ //size must be bigger than 0
		std::cerr << "Error! " << "Can't validate size" << "\n";
		return 0;
	}
	if(!Einput::validate_brackets(s)){
		std::cerr << "Error! " << "Can't validate brackets" << "\n";
		return 0;
	}
	if(!Einput::validate_characters(s)){
		std::cerr << "Error! " << "Can't validate characters" << "\n";
		return 0;
	}
		
	return 1;	
}
