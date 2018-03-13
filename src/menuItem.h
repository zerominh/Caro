#pragma once

#include "text.h"
#include <SDL.h>

class MenuItem : public Text{
public:
	MenuItem(const Text & text);
	void listenToClick(SDL_Event &e);
	inline bool isClicked() { return _isClicked;}
	
	
private:
	bool _isClicked = false;
	
	
	
};
