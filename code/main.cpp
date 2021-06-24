#include "app.h"
#include "gui/include/component.h"

int main()
{
	if (!Efonts::basic.loadFromFile("assets/fonts/CheGuevaraBarry-Brown.ttf"))
		std::cout << "loading font failed \n";
	
	Eapplication app{"GUI"};
	app.run();
	return 0;
}
