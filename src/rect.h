#pragma once

#include "window.h"

class Rect{
public:
	Rect(int w, int h, int x, int y, int r, int g, int b, int a);
	Rect(int w, int h, int x, int y, std::string image_path);
	~Rect();
	void draw() const;
	void draw(const Window & window);
	void draw(int x, int y);
	void pollEvents(SDL_Event & e);
	void setH(int h){
		_h = h;
	}
	void setW(int w){
		_w = w;
	}
private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;	
	SDL_Texture * _texture = nullptr;	
};
