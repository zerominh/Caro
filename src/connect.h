#pragma once

#include <iostream>
#include <vector>
#include "window.h"
#include "text.h"

enum End{
	hoaco, player1, player2
};

enum Checker{
	O = -1, _ = 0, X = 1
};


enum Mode {
	playerVsPlayerMode, playerVsCompterMode
};

struct Cell{
	int row = -1;
	int column = -1;
};

class Connect{
	public:
		static 	const int NUM_CELL_WIDTH = 18;
		static	const int NUM_CELL_HEIGHT = 18;
		static	const int CELL_W = 30;
		static	const int CELL_H = 30;
		static	const int WINDOW_WIDTH = CELL_W*NUM_CELL_WIDTH;
		static	const int WINDOW_HEIGHT = CELL_H*NUM_CELL_HEIGHT;
		
		static	const int COLUMN = NUM_CELL_WIDTH;
		static	const int ROW = NUM_CELL_HEIGHT;
		
	public:
		Connect();
		~Connect();
		
		inline int** getTable() const { return _table;}
		
		bool isValidCell(const Cell & c) const;
		inline void changeChecker() { _checker *= -1;}
		void update(const Cell & c);
		bool isEndGame();
		void showResult(Window & window) const;
		void play(Window & window);
		void playVsPlayer(Window & window);
		void playVsComputer(Window & window);
		void showResultPlayerVsPlayerMode(Window & window) const;
		void showResultPlayerVsComputerMode(Window & window) const;
		
	private:
		bool init();
		bool checkCol(const int & row, const int & column) const;
		bool checkRow(const int & row, const int & column) const;
		bool checkDia1(const int & row, const int & column) const;
		bool checkDia2(const int & row, const int & column) const;
		
	public:
		int mode = playerVsPlayerMode;
	private:
		
		int ** _table = nullptr;
		int _checker = X;
		int _endResult = hoaco;
		std::vector<Cell> _history;
		std::vector<Cell> _historyPlayer1;
		std::vector<Cell> _historyPlayer2;
};
