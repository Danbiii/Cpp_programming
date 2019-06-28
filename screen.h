#pragma once
using namespace std;
#include <ncurses.h>
#include <sstream>
#include <cstring>


class screen
{
	public:
		// basic screen setting
		void wCenterTitle(WINDOW *win, const char* title);
		void wclrscr(WINDOW *win);

		// background, clear screen
		void base_w(int _r, int _c, int _y, int _x, int color);
		void game_w(int _r, int _c, int _y, int _x, int color);
		void clear_w(int _r, int _c, int _y, int _x, int color);
		void last_w(int _r, int _c, int _y, int _x, int color);

		// current state
		void step_w(int _r, int _c, int _y, int _x, int color, int step);
		void push_w(int _r, int _c, int _y, int _x, int color, int push);
		void level_w(int _r, int _c, int _y, int _x, int color, int level);
};
