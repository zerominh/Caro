#include "menu.h"

Menu::Menu() {
	
}

void Menu::add(MenuItem & m) {
	_menu.push_back(m);
}


void Menu::display(int x, int y, SDL_Renderer * renderer, const Window & window) const
{
	if(!isEmpty()) {
		int d = 50;
		int order = 0;
		for(auto i = _menu.begin(); i != _menu.end(); ++i)
		{
			i->display(x , y+ order*d, renderer);
			++order;
		}
		window.clear();
	}
}


void Menu::listenToClick(SDL_Event & e)
{
	if(!isEmpty()) {
		for(auto i = _menu.begin(); i != _menu.end(); ++i)
		{
			i->listenToClick(e);
			if(i->isClicked()) {
				_isClicked = true;
			}
		}
	}
}
