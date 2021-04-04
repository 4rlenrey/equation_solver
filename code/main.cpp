#include "app.h"
#include "gui/include/components/button.h"

int main()
{
	if (!Ebutton::font.loadFromFile("assets/fonts/CheGuevaraBarry-Brown.ttf"))
		std::cout << "loading font failed \n";
	

	Eapplication app{"GUI"};
	app.run();
	return 0;
}
