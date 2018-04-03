#pragma once

#include <iostream>
#include <vector>
#include "window.h"
#include "text.h"
#include "utils.h"
#include <ctime>
#include <cmath>
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
		
		
		long FIGHT[8] = {0, 3, 24, 192, 1536, 1288, 98304, 786432};
		long DEFENCE[8] = {0, 1, 9, 81, 729, 6561, 59049, 472392};
		
		static	const int COLUMN = NUM_CELL_WIDTH;
		static	const int ROW = NUM_CELL_HEIGHT;
		
		static const int TIME_ELAPSE = 5;
		
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
		void generateCell(Cell &);
		long caculateFight(int, int);
		long caculateDefence(int, int);
		long TCDuyetDoc(int, int);
		long TCDuyetNgang(int, int);
		long TCDuyetCheoXuoi(int, int);
		long TCDuyetCheoNguoc(int, int);
		
		long PNDuyetDoc(int, int);
		long PNDuyetNgang(int, int);
		long PNDuyetCheoXuoi(int, int);
		long PNDuyetCheoNguoc(int, int);
		
		
		
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
		
		int _checkerOfPlayer = X;
		int _checkerOfComputer = O;
};
