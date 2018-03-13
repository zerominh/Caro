#include "menuItem.h"

MenuItem::MenuItem(const Text & text):
	Text(text)
{

}

void MenuItem::listenToClick(SDL_Event &e)
{
		switch(e.type) {
			case SDL_MOUSEBUTTONDOWN:
				if(e.button.x >= _text_rect.x && e.button.x <= _text_rect.x + _text_rect.w
					&& e.button.y >= _text_rect.y && e.button.y <= _text_rect.y + _text_rect.h) {
					_isClicked = true;
				}
				break;
			default:
				break;
		}
}

