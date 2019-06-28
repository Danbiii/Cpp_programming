// #include "screen.h"
#include "map.h"
#include <iostream>
#include <fstream>
using namespace std;

int step, push, goal;

int main()
{
	// map load
	const int MAP_COUNT = 5;
	ifstream is;
	is.open("input.txt");
	if (!is) {
		cerr << "파일을 오픈할 수 없습니다." << endl;
		//exit(1);
	}

	// initial map array
	int Map[5][11][11];
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				is >> Map[k][i][j];
			}
		}
	}

	// level lnput
	int level_choice = -1;
	while (!(level_choice >= 1 && level_choice <= MAP_COUNT)) {
		cout << "진행하길 원하는 레벨을 입력하십시오." << "(1 ~ " << MAP_COUNT << ") : ";
		cin >> level_choice;
	}
	level_choice--;

	// level map array
	map M;
	vector<vector<int> > mapArr(11, vector<int>(11, 0));
	mapArr = M.resetMapArr(mapArr, Map, level_choice);

	// basic setting
	int maxy, maxx;
	initscr();
	resize_term(45, 80);
	getmaxyx(stdscr, maxy, maxx);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_YELLOW);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_BLACK, COLOR_RED);
	init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(7, COLOR_WHITE, COLOR_CYAN);
	init_pair(8, COLOR_WHITE, COLOR_GREEN);
	init_pair(9, COLOR_WHITE, COLOR_RED);

	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	refresh();

	// initail game screen
	screen SC;

	SC.base_w(maxy, maxx, 0, 0, 3);
	SC.game_w(maxy - 6, maxx - 5, 5, 2, 2);

	// show map
	vector<int> y_x = M.mapshow(mapArr, maxx, step, push, level_choice);
	int c_y = y_x[0];
	int c_x = y_x[1];

	int key, key2;
	while (1)  // r is reset button
	{
		key = getch();
		if (key == 114) {
			mapArr = M.resetMapArr(mapArr, Map, level_choice);

			step = 0;
			push = 0;

			y_x = M.mapshow(mapArr, maxx, step, push, level_choice);
			c_y = y_x[0];
			c_x = y_x[1];

			continue;
		}

		mapArr = M.wayControl(mapArr, key, c_y, c_x);
		y_x = M.mapshow(mapArr, maxx, step, push, level_choice);
		c_y = y_x[0];
		c_x = y_x[1];

		if (goal == 0) {  	// clear
			level_choice++;
			if (level_choice > 4) {
				SC.last_w(maxy / 2, maxx / 2, maxy / 4, maxx / 4, 8);
				getch();
				break;
			}
			else {
				SC.clear_w(maxy / 2, maxx / 2, maxy / 4, maxx / 4, 9);
			}

			key2 = getch();
			if (key2 == 110) {  // n is next level
				mapArr = M.resetMapArr(mapArr, Map, level_choice);

				step = 0;
				push = 0;

				y_x = M.mapshow(mapArr, maxx, step, push, level_choice);
				c_y = y_x[0];
				c_x = y_x[1];
			}
			else if (key2 == 101) {  // e is exit game
				break;
			}
		}
	}
	endwin();

	return 0;
}
