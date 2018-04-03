#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class Window{
public:
	Window(const std::string &title, const int width, const int height);
	~Window();
	
	void setClosed(const bool) {
		_closed = true;
	}
	inline bool isClosed() const {return _closed;}
	void pollEvents(SDL_Event & e);
	void getMousePos(SDL_Event & e, int & x, int & y);
	void clear() const;
	inline int getHeight() const {return _height;}
	inline int getWidth() const {return _width;}
	inline SDL_Window* getSDL_Window() const {return _window;}
	bool isClicked(SDL_Event &e);
private:
	bool init();
	
private:
	std::string _title = "window";
	int _height = 540;
	int _width = 540;
	bool _closed = false;
	
	SDL_Window* _window = nullptr;
public:
	
	static SDL_Renderer * renderer;
};
