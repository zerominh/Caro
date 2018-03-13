#include "connect.h"
#include "utils.h"

Connect::Connect()
{
	if(!init()) {
		std::cerr << "Failed to init.\n";
	}
	
	
}

Connect::~Connect(){
	delete[] *_table;
	delete[] _table;
}

bool Connect::init()
{
	_table = new int* [Connect::ROW];
	for(int i = 0; i < Connect::ROW; ++i)
	{
		_table[i] = new int[Connect::COLUMN];
	}
	
	for(int i = 0; i < Connect::ROW; ++i)
	{
		for(int j = 0; j < Connect::COLUMN; ++j)
		{
			_table[i][j] =  0;
		}
	}
	
	if(_table == nullptr){
		return false;
	} else return true;
}


bool Connect::isValidCell(const Cell & c) const
{
	return (c.row >= 0 && c.column >= 0 &&
			c.row <= Connect::ROW && c.column <= Connect::COLUMN&&
			_table[c.row][c.column] == _);
}




void Connect::update(const Cell & c)
{
	_history.push_back(c);
	switch(_checker) {
		case X:
			_historyPlayer1.push_back(c);
			break;
		case O:
			_historyPlayer2.push_back(c);
			break;
		default:
			break;
	}
	
	
	
	_table[c.row][c.column] = _checker;
	
}


void Connect::showResult(Window & window) const {
	
	
	switch(mode) {
		case playerVsPlayerMode:
			showResultPlayerVsPlayerMode(window);
			break;
		case playerVsCompterMode:
			showResultPlayerVsComputerMode(window);
			break;
	}
}


void Connect::showResultPlayerVsPlayerMode(Window & window) const {
	std::string message_text;
	std::string path = "res/timesbd.ttf";
	message_text = "Hoa Co";
	Text text1(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	
	
	message_text = "Player1 Win";
	Text text2(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	
	
	message_text = "Player2 Win";
	Text text3(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	
	SDL_Event e;
	switch(_endResult) {
		case hoaco:

			do {
				if(SDL_PollEvent(&e)) {
					window.pollEvents(e);
				}
				text1.display(200, 10, Window::renderer);
				window.clear();
			} while(!window.isClosed());
			break;
			
		case player1:
			
			do {
				if(SDL_PollEvent(&e)) {
					window.pollEvents(e);
				}
				text2.display(200, 10, Window::renderer);
				window.clear();
			} while(!window.isClosed());

			break;
			
		case player2:
			
			do {
				if(SDL_PollEvent(&e)) {
					window.pollEvents(e);
				}
				text3.display(200, 10, Window::renderer);
				window.clear();
			} while(!window.isClosed());
			break;
			
		default:
			break;
	}
}

void Connect::showResultPlayerVsComputerMode(Window & window) const {
	std::string message_text;
	std::string path = "res/timesbd.ttf";
	message_text = "Hoa Co";
	Text text1(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	
	
	message_text = "Player Win";
	Text text2(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	
	
	message_text = "Computer Win";
	Text text3(Window::renderer, path, 30, message_text, {255, 0, 0, 255});
	
	SDL_Event e;
	switch(_endResult) {
		case hoaco:

			do {
				if(SDL_PollEvent(&e)) {
					window.pollEvents(e);
				}
				text1.display(200, 10, Window::renderer);
				window.clear();
			} while(!window.isClosed());
			break;
			
		case player1:
			
			do {
				if(SDL_PollEvent(&e)) {
					window.pollEvents(e);
				}
				text2.display(200, 10, Window::renderer);
				window.clear();
			} while(!window.isClosed());

			break;
			
		case player2:
			
			do {
				if(SDL_PollEvent(&e)) {
					window.pollEvents(e);
				}
				text3.display(200, 10, Window::renderer);
				window.clear();
			} while(!window.isClosed());
			break;
			
		default:
			break;
	}
}

bool Connect::isEndGame() {
	if(_history.size() == Connect::COLUMN*Connect::ROW){
		_endResult = hoaco;
		return true;
	}
	
	if(_history.size() == 0) {
		return false;
	}
	
	if(_checker == X){
		
		if(_historyPlayer1.size() == 0) {
			return false;
		}
		
		for(std::vector<Cell>::iterator i = _historyPlayer1.begin(); i != _historyPlayer1.end(); ++i)
		{
			if(checkCol(i->row, i->column) || checkRow(i->row, i->column) || checkDia1(i->row, i->column) || checkDia2(i->row, i->column))
			{
				_endResult = player1;
				return true;
			};
		}
	} else {
		if(_historyPlayer2.size() == 0) {
			return false;
		}
		
		for(std::vector<Cell>::iterator i = _historyPlayer2.begin(); i != _historyPlayer2.end(); ++i)
		{
			if(checkCol(i->row, i->column) || checkRow(i->row, i->column) || checkDia1(i->row, i->column) || checkDia2(i->row, i->column))
			{
				_endResult = player2;
				return true;
			};
		}
	}
	
	return false;
	
	
}





bool Connect::checkCol(const int & row, const int & column) const {
	if(row > Connect::ROW - 5){
		return false;
	}
	
	
	for(int i = 1; i < 5; ++i)
	{
		if(_table[row + i][column] != _checker){
			return false;
		}
	}
	
	if(row == 0 || row + 5 == Connect::ROW){
		return true;
	}
	
	if(_table[row - 1][column] == _ || _table[row +5][column] == _){
		return true;
	}
	
	return false;
}



bool Connect::checkRow(const int & row, const int & column) const {
	if(column > Connect::COLUMN - 5){
		return false;
	}
	
	
	for(int i = 1; i < 5; ++i)
	{
		if(_table[row ][column+i] != _checker){
			return false;
		}
	}
	
	if(column == 0 || column + 5 == Connect::COLUMN){
		return true;
	}
	
	if(_table[row][column-1] == _ || _table[row][column+5] == _){
		return true;
	}
	
	return false;
}




bool Connect::checkDia2(const int & row, const int & column) const {

	if(row < 4 || column > Connect::COLUMN - 5)
	{
		return false;
	}
	
	for(int i = 1; i < 5; ++i)
	{
		if(_table[row - i][column + i] != _checker) {
			return false;
		}
	}
	
	if(column == 0 || row == 4 || row == Connect::ROW - 5 || column == Connect::COLUMN - 5) {
		return true;
	}
	
	if(_table[row-1][column+1] == _ || _table[row-5][column+5] == _) {
		return true;
	}
	
	return false;
}


bool Connect::checkDia1(const int & row, const int & column) const {
	
	if(row > Connect::ROW - 5 || column > Connect::COLUMN - 5)
	{
		return false;
	}
	
	for(int i = 1; i < 5; ++i)
	{
		if(_table[row + i][column + i] != _checker) {
			return false;
		}
	}
	
	if(column == 0 || row == 0 || row == Connect::ROW - 5 || column == Connect::COLUMN - 5) {
		return true;
	}
	
	if(_table[row-1][column-1] == _ || _table[row+5][column+5] == _) {
		return true;
	}
	
	return false;	
}



void Connect::play(Window & window)
{
	switch(mode) {
		case playerVsPlayerMode:
			playVsPlayer(window);
			break;
		case playerVsCompterMode:
			playVsComputer(window);
			break;
	}
}



void Connect::playVsPlayer(Window & window) {
	Rect table(window.getWidth(), window.getHeight(), 0, 0, "res/background.png");
	Rect cross(Connect::CELL_W, Connect::CELL_H, 0, 0, "res/cross.png");
	Rect nought(Connect::CELL_W, Connect::CELL_H, 0, 0, "res/nought.png");
	
	while(!window.isClosed()) {
		Cell c;
		Utils::pollEvents(window, c.column, c.row);
		
		if(c.column >= 0 && c.row >= 0 && c.column <= Connect::WINDOW_WIDTH && c.row <= Connect::WINDOW_HEIGHT){
			c.column /= Connect::CELL_W;
			c.row /= Connect::CELL_H;
			if(isValidCell(c)){

				update(c);
				if(isEndGame()) {
					showResult(window);
					break;
				}
				
				changeChecker();
			}	
		}
		
		Utils::draw(_table, window, table, cross, nought);
	}	
}



void Connect::playVsComputer(Window & window) {
	Rect table(window.getWidth(), window.getHeight(), 0, 0, "res/background.png");
	Rect cross(Connect::CELL_W, Connect::CELL_H, 0, 0, "res/cross.png");
	Rect nought(Connect::CELL_W, Connect::CELL_H, 0, 0, "res/nought.png");
	
	while(!window.isClosed()) {
		Cell c;
		Utils::pollEvents(window, c.column, c.row);
		
		if(c.column >= 0 && c.row >= 0 && c.column <= Connect::WINDOW_WIDTH && c.row <= Connect::WINDOW_HEIGHT){
			c.column /= Connect::CELL_W;
			c.row /= Connect::CELL_H;
			if(isValidCell(c)){

				update(c);
				if(isEndGame()) {
					showResult(window);
					break;
				}
				
				changeChecker();
			}	
		}
		
		Utils::draw(_table, window, table, cross, nought);
	}	
}
