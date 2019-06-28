#include "screen.h"

void screen::wCenterTitle(WINDOW *win, const char * title)
{
	int x, maxy, maxx, stringsize;
	getmaxyx(win, maxy, maxx);
	stringsize = 4 + strlen(title);
	x = (maxx - stringsize) / 2;
	mvwaddch(win, 0, x, ACS_RTEE);
	waddch(win, ' ');
	waddstr(win, title);
	waddch(win, ' ');
	waddch(win, ACS_LTEE);
}

void screen::wclrscr(WINDOW *win)
{
	int y, x, maxy, maxx;
	getmaxyx(win, maxy, maxx);
	for (y = 0; y < maxy; y++)
		for (x = 0; x < maxx; x++)
			mvwaddch(win, y, x, ' ');
}

void screen::base_w(int _r, int _c, int _y, int _x, int color)
{
	WINDOW *base_win;
	base_win = newwin(_r, _c, _y, _x);
	wattrset(base_win, COLOR_PAIR(color) | WA_BOLD);
	wclrscr(base_win);
	box(base_win, 0, 0);
	wCenterTitle(base_win, "MENU");
	wrefresh(base_win);
	delwin(base_win);
}

void screen::game_w(int _r, int _c, int _y, int _x, int color)
{
	WINDOW *main_win;
	main_win = newwin(_r, _c, _y, _x);
	wattrset(main_win, COLOR_PAIR(color) | WA_BOLD);
	wclrscr(main_win);
	box(main_win, 0, 0);
	wCenterTitle(main_win, "Game Window");
	mvwaddstr(main_win, _r - 1, _c / 4 - 2, "If you want to reset the Game, press button 'r'");
	wrefresh(main_win);
	delwin(main_win);
}

void screen::step_w(int _r, int _c, int _y, int _x, int color, int step)
{
	WINDOW *option_win;
	option_win = newwin(_r, _c, _y, _x);
	wattrset(option_win, COLOR_PAIR(color) | WA_BOLD);
	wclrscr(option_win);
	box(option_win, 0, 0);
	wCenterTitle(option_win, "Step");
	mvwprintw(option_win, 1, _y + _c / 2 - 2, "%d", step);
	wrefresh(option_win);
	delwin(option_win);
}

void screen::push_w(int _r, int _c, int _y, int _x, int color, int push)
{
	WINDOW *option_win;
	option_win = newwin(_r, _c, _y, _x);
	wattrset(option_win, COLOR_PAIR(color) | WA_BOLD);
	wclrscr(option_win);
	box(option_win, 0, 0);
	wCenterTitle(option_win, "Push");
	mvwprintw(option_win, 1, _y + _c / 2 - 2, "%d", push);
	wrefresh(option_win);
	delwin(option_win);
}

void screen::level_w(int _r, int _c, int _y, int _x, int color, int level)
{
	WINDOW *option_win;
	option_win = newwin(_r, _c, _y, _x);
	wattrset(option_win, COLOR_PAIR(color) | WA_BOLD);
	wclrscr(option_win);
	box(option_win, 0, 0);
	wCenterTitle(option_win, "Level");
	mvwprintw(option_win, 1, _y + _c / 2 - 2, "%d", level);
	wrefresh(option_win);
	delwin(option_win);
}

void screen::clear_w(int _r, int _c, int _y, int _x, int color)
{
	WINDOW *clear_win;
	clear_win = newwin(_r, _c, _y, _x);
	wattrset(clear_win, COLOR_PAIR(color) | WA_BOLD);
	wclrscr(clear_win);
	box(clear_win, 0, 0);
	wCenterTitle(clear_win, "CLEAR");
	mvwaddstr(clear_win, _r / 3, _c / 3, "Congraturation!");
	mvwaddstr(clear_win, _r / 3 * 2, _c / 4, "EXIT(E)  /  NEXT_LEVEL(N)");
	wrefresh(clear_win);
	delwin(clear_win);
}

void screen::last_w(int _r, int _c, int _y, int _x, int color)
{
	WINDOW *last_win;
	last_win = newwin(_r, _c, _y, _x);
	wattrset(last_win, COLOR_PAIR(color) | WA_BOLD);
	wclrscr(last_win);
	box(last_win, 0, 0);
	wCenterTitle(last_win, "CLEAR");
	mvwaddstr(last_win, _r / 3, _c / 2 - 5, "ALL CLEAR!");
	mvwaddstr(last_win, _r / 3 * 2, _c / 4, "Press any key to exit");
	wrefresh(last_win);
	delwin(last_win);
}
