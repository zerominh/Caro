#include <SDL.h>
#include <iostream>
#include "window.h"
#include "string"
#include "connect.h"
#include "text.h"
#include "menuItem.h"
#include "menu.h"


int main( int argc, char* args[] ){	

	Window window("Caro", Connect::WINDOW_WIDTH, Connect::WINDOW_HEIGHT);
	
	Connect caro;
	
	
	std::string path = "res/timesbd.ttf";
	std::string message_text = "Caro Game";
	Text text(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	text.display(200, 10, Window::renderer);
	text.changeTextColor(Window::renderer, path, 30, message_text, {0, 255, 0, 255});
	text.display(200, 10, Window::renderer);
	
	message_text = "New game";
	Text new_game_text(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	
	message_text = "Exit";
	Text exit_text(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	

	MenuItem menuItem_new_game_text(new_game_text);
	MenuItem menuItem_exit_text(exit_text);
	
	menuItem_new_game_text.display(200, 200, Window::renderer);
	menuItem_exit_text.display(200, 250, Window::renderer);
	window.clear();
	
	
	message_text = "Player vs Player";
	Text playerVsPlayerText(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	MenuItem menuPlayerVsPlayerText(playerVsPlayerText);
	
	message_text = "Player vs Computer";
	Text playerVsComputerText(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	MenuItem menuPlayerVsComputerText(playerVsComputerText);
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
	
	
	
	
	
	
	return 0;
}
