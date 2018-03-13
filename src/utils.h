#pragma once
#include <SDL.h>
#include "window.h"
#include "rect.h"
#include "connect.h"

class Utils{
public:
	static void pollEvents(Window & w, int & x, int & y);
	static void draw(int**a, Window & window, Rect & table, Rect & cross, Rect & nought);
};
