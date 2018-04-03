#include <SDL.h>
#include <iostream>
#include "window.h"
#include "string"
#include "connect.h"
#include "text.h"
#include "menuItem.h"
#include "menu.h"


MenuItem& createMenuItem(std::string message_text, const std::string & path,
	const Window & window, const int & font_size, const SDL_Color & color)
{
	Text text(Window::renderer, path, font_size, message_text, color);
	MenuItem menuItem(text);
	return menuItem;
}




void play(Window & window)
{
	
	
	Connect caro;
	
	int font_size = 30;
	
	
	
	std::string path = "res/timesbd.ttf";
	std::string message_text = "Caro Game";
	
	Text text(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	text.display(200, 10, Window::renderer);
	text.changeTextColor(Window::renderer, path, 30, message_text, {0, 255, 0, 255});
	text.display(200, 10, Window::renderer);
	

	SDL_Color color({255, 0, 0, 255});

	MenuItem menuItem_new_game_text= createMenuItem("New game", path, window, font_size, color);
	MenuItem menuItem_exit_text = createMenuItem("Exit", path, window, font_size, color);
	
	menuItem_new_game_text.display(200, 200, Window::renderer);
	menuItem_exit_text.display(200, 250, Window::renderer);
	window.clear();
	
	MenuItem menuPlayerVsPlayerText = createMenuItem("Player vs Player", path, window, font_size, color);
	MenuItem menuPlayerVsComputerText = createMenuItem("Player vs Computer", path, window, font_size, color);
	
	do {
		SDL_Event e;
		if(SDL_PollEvent(&e)) {
			window.pollEvents(e);
			menuItem_new_game_text.listenToClick(e);
			menuItem_exit_text.listenToClick(e);
		}
		if(menuItem_new_game_text.isClicked()) {
			menuPlayerVsPlayerText.display(200, 200, Window::renderer);
			menuPlayerVsComputerText.display(200, 250, Window::renderer);
			window.clear();
			do {
				SDL_Event e;
				if(SDL_PollEvent(&e)) {
					window.pollEvents(e);
					menuPlayerVsPlayerText.listenToClick(e);
					menuPlayerVsComputerText.listenToClick(e);
				}
				
				if(menuPlayerVsPlayerText.isClicked()) {
					caro.play(window);
				} else if(menuPlayerVsComputerText.isClicked()) {
					caro.mode = playerVsCompterMode;
					caro.play(window);
				}
				
			} while(!window.isClosed() && !caro.isEndGame());
			
		} else if(menuItem_exit_text.isClicked()) {
			window.setClosed(true);
		}
		
	}while(!window.isClosed() && !caro.isEndGame());
}

void rendEndGame(Window & window, const MenuItem & menuContinue, const MenuItem & menuExit)
{
	SDL_Event e;
	do {
		
		if(SDL_PollEvent(&e)) {
			window.pollEvents(e);
		}
	}while(!window.isClicked(e) && !window.isClosed());
}

int main( int argc, char* args[] ){	
 
	Window window("Caro", Connect::WINDOW_WIDTH, Connect::WINDOW_HEIGHT);
	play(window);
	int font_size = 30;
	std::string path = "res/timesbd.ttf";

	SDL_Color color({255, 0, 0, 255});

	MenuItem menuContinue = createMenuItem("Continue", path, window, font_size, color);
	MenuItem menuExit = createMenuItem("Exit", path, window, font_size, color);
	
	rendEndGame(window, menuContinue, menuExit);
	
	
	menuContinue.display(200, 200, Window::renderer);
	menuExit.display(200, 250, Window::renderer);
	window.clear();
	
	do {

		SDL_Event e;
		if(SDL_PollEvent(&e)) {
			window.pollEvents(e);
			menuContinue.listenToClick(e);
			menuExit.listenToClick(e);
		}
		
		if(menuExit.isClicked()) {
			window.setClosed(true);
		} else if(menuContinue.isClicked()) {
			play(window);
			rendEndGame(window, menuContinue, menuExit);
		}
	} while(!window.isClosed());

	
	
	return 0;
}
