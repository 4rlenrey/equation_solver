#include "../include/component.h"

std::vector<Ecomponent*> Ecomponent::ecomponents = {};

Ecomponent::Ecomponent()
{
	add_to_vector();
}

void Ecomponent::add_to_vector()
{
	ecomponents.push_back(this);
}

Ecomponent::~Ecomponent()
{
    ecomponents.erase(std::remove(begin(ecomponents), end(ecomponents), this), end(ecomponents));
}

