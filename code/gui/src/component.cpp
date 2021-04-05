#include "../include/component.h"

std::vector<Ecomponent *> Ecomponent::ecomponents = {};
std::vector<Efocusable *> Efocusable::efocusables = {};

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

Efocusable::Efocusable()
{
	efocusables.push_back(this);
}

Efocusable::~Efocusable()
{
	efocusables.erase(std::remove(begin(efocusables), end(efocusables), this), end(efocusables));
}

void Efocusable::activate()
{

	if(!active)
	{
		active = true;
		rectangle.setFillColor(color_active);
	}
}
void Efocusable::deactivate()
{
	if(active)
	{
		rectangle.setFillColor(color_deactive);
		active = false;
	}
}