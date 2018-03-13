#include "window.h"
#include <SDL_image.h>
#include <iostream>

SDL_Renderer * Window::renderer = nullptr;

Window::Window(const std::string &title, const int width, const int height):
	_title(title), _height(height), _width(width){
		_closed = !init();
	}

Window::~Window(){
	SDL_DestroyRenderer(Window::renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool Window::init(){
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cerr << "Failed to init SDL. \n";
		return false;
	}
	
	if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
		std::cerr << "Failed to init SDL_image. \n";
		return false;
	} 
	
	if(TTF_Init() == -1) {
		std::cerr << "Failed to init SDL_ttf. \n";
		return false;
	}
	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width,
		_height,
		SDL_WINDOW_SHOWN
	);
	
	if(_window == nullptr){
		std::cerr << "Failed to create window.\n";
		return false;
	}
	Window::renderer = SDL_CreateRenderer(_window, 2, SDL_RENDERER_ACCELERATED);
	if(Window::renderer == nullptr){
		std::cerr << "Failed to create rendered.\n";
		return false;
	}
	return true;
}



void Window::pollEvents(SDL_Event &e){
	switch(e.type){
			case SDL_QUIT:
				_closed = true;
				break;
			case SDL_KEYDOWN:
				switch(e.key.keysym.sym){
					case SDLK_ESCAPE:
						_closed = true;
						break;
						
					default:
						break;
				}
			default:
				break;
		}
}



void Window::getMousePos(SDL_Event &e, int & x, int & y){
	switch(e.type) {
			case SDL_MOUSEBUTTONDOWN:
				x =  e.button.x;
				y =  e.button.y;
				break;
			default:
				break;
		}
}


void Window::clear() const {
	
	SDL_RenderPresent(Window::renderer);
	SDL_SetRenderDrawColor(Window::renderer, 0, 0, 0, 255);
	SDL_RenderClear(Window::renderer);
	
}
