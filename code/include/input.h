#include <iostream>

namespace Einput{
	bool validate(const std::string&);
	bool validate_brackets(const std::string&);
	bool validate_characters(const std::string&);
	std::string simplify(const std::string&);
	bool fix_brackets(std::string&);
}