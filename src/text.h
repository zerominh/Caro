#pragma once

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>


class Text {
public:
	Text(SDL_Renderer* renderer,const std::string & font_path, int font_size, const std::string &message_text, const SDL_Color & color);
	void display(int x, int y, SDL_Renderer * renderer) const;
	static SDL_Texture* loadFont(SDL_Renderer* renderer,const std::string & font_path, int font_size, const std::string &message_text, const SDL_Color & color);
	void changeTextColor(SDL_Renderer * renderer, const std::string & font_path, int font_size, const std::string &message_text, const SDL_Color & color);
//	~Text();
private:
	SDL_Texture* _text_texture = nullptr;
public:
	mutable SDL_Rect _text_rect;
};
