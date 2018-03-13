#include "rect.h"
#include <SDL_image.h>
#include <string>
#include <iostream>

Rect::Rect(int w, int h, int x, int y, int r, int g, int b, int a):
	_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
		
		
}
Rect::Rect(int w, int h, int x, int y, std::string image_path):
	_w(w), _h(h), _x(x), _y(y)
	{
		auto s = IMG_Load(image_path.c_str());
		if(!s){
			std::cerr << "Failed to create surface.\n";
		}
		
		_texture = SDL_CreateTextureFromSurface(Window::renderer, s);
		if(!_texture){
			std::cerr << "Failed to create texture.\n";
		}
		
		
		SDL_FreeSurface(s);
		
	}


Rect::~Rect(){
	SDL_DestroyTexture(_texture);
}


void Rect::draw(const Window & window) {
	int w, h;
	SDL_GetWindowSize(window.getSDL_Window(), &w, &h);
	setW(w);
	setH(h);
	SDL_Rect rect = {_x, _y, _w, _h};
	
	if(_texture) {
		SDL_RenderCopy(Window::renderer, _texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(Window::renderer, &rect);
	}
}


void Rect::draw() const {
	SDL_Rect rect = {_x, _y, _w, _h};
	
	if(_texture) {
		SDL_RenderCopy(Window::renderer, _texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(Window::renderer, &rect);
	}
	
}


void Rect::draw(int x, int y) {
	SDL_Rect rect = {x, y, _w, _h};
	
	if(_texture) {
		SDL_RenderCopy(Window::renderer, _texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(Window::renderer, &rect);
	}
}

void Rect::pollEvents(SDL_Event & e){
	switch(e.type){
			case SDL_KEYDOWN:
				
				switch(e.key.keysym.sym){
						case SDLK_LEFT:
							_x -= 4;
							break;
						
						default:
							break;
					}
					
			default:
				break;
		}
}
