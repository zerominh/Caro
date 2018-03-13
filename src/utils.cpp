#include "utils.h"

void Utils::pollEvents(Window & w, int & x, int & y) {
	SDL_Event e;
	if(SDL_PollEvent(&e)) {
		w.pollEvents(e);
		w.getMousePos(e, x, y);
	}
}

void Utils::draw(int**a, Window & window, Rect & table, Rect & cross, Rect & nought)
{
	table.draw();
		
	for(int i = 0; i < Connect::ROW; ++i)
	{
		for(int j = 0; j < Connect::COLUMN; ++j)
		{
			switch(a[i][j]) {
				case 1:
					cross.draw(j*Connect::CELL_W, i*Connect::CELL_H);
					break;
				case -1:
					nought.draw(j*Connect::CELL_W, i*Connect::CELL_H);
					break;
				default:
					break;
			}
		}
	}
		
	window.clear();
}
