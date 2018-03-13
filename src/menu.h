#pragma once

#include "menuItem.h"
#include <vector>
#include "window.h"
#include <SDL.h>

class Menu {
public:
	Menu();
	void add(MenuItem & m);
	inline bool isEmpty() const { return _menu.empty();}
	void display(int x, int y, SDL_Renderer * renderer, const Window & window) const;
	inline bool isClicked() const {return _isClicked;}
	void listenToClick(SDL_Event & e);
public:
	std::vector<MenuItem> _menu;
	bool _isClicked = false;
};
