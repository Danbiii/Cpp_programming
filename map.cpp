#include "map.h"

extern int step, push, goal;

void map::character(int _y, int _x)
{
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			WINDOW *win;
			win = newwin(1, 1, _y + y, _x + x);
			if ((x == 1 || x == 4) && (y == 1))
				wbkgd(win, COLOR_PAIR(2));
			else
				wbkgd(win, COLOR_PAIR(1));
			wrefresh(win);
			delwin(win);
		}
	}
}

void map::target(int _y, int _x)
{
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			WINDOW *win = newwin(1, 1, _y + y, _x + x);
			if ((x >= 1 && x <= 4) && (y == 1)
				|| (x >= 2 && x <= 3) && (y == 0 || y == 2))
				wbkgd(win, COLOR_PAIR(2));
			else
				wbkgd(win, COLOR_PAIR(5));
			wrefresh(win);
			delwin(win);
		}
	}
}

void map::tile(int _y, int _x)
{
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			WINDOW *win = newwin(1, 1, _y + y, _x + x);
			wbkgd(win, COLOR_PAIR(4));
			wrefresh(win);
			delwin(win);
		}
	}
}

void map::box(int _y, int _x)
{
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			WINDOW *win = newwin(1, 1, _y + y, _x + x);
			if ((x >= 2 && x <= 3) && (y == 1)
				|| (x <= 1 || x >= 4) && (y == 0 || y == 2))
				wbkgd(win, COLOR_PAIR(6));
			else
				wbkgd(win, COLOR_PAIR(8));
			wrefresh(win);
			delwin(win);
		}
	}
}

void map::wall(int _y, int _x)
{
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			WINDOW *win = newwin(1, 1, _y + y, _x + x);
			if (x >= 5 || y == 2)
				wbkgd(win, COLOR_PAIR(3));
			else
				wbkgd(win, COLOR_PAIR(7));
			wrefresh(win);
			delwin(win);
		}
	}
}

void map::blank(int _y, int _x)
{
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			WINDOW *win = newwin(1, 1, _y + y, _x + x);
			wbkgd(win, COLOR_PAIR(2));
			wrefresh(win);
			delwin(win);
		}
	}
}

vector<int> map::mapshow(vector<vector<int> > mapArr, int maxx, int step, int push, int level_choice)
{
	vector<int> y_x;
	screen SC;
	goal = 0;
	for (int y = 0; y < 11; y++) {
		for (int x = 0; x < 11; x++) {
			if (mapArr[y][x] == 0) tile(y * 3 + 10, x * 6 + 10);
			else if (mapArr[y][x] == 1) wall(y * 3 + 10, x * 6 + 10);
			else if ((mapArr[y][x] == 2) || (mapArr[y][x] == 12)) box(y * 3 + 10, x * 6 + 10);  // 12�� target ������
			else if (mapArr[y][x] == 3)
			{
				goal++;
				target(y * 3 + 10, x * 6 + 10);
			}
			else if (mapArr[y][x] == 4) blank(y * 3 + 10, x * 6 + 10);
			else if (mapArr[y][x] == 5)
			{
				y_x.push_back(y);
				y_x.push_back(x);

				character(y * 3 + 10, x * 6 + 10);
			}
			else if (mapArr[y][x] == 15)
			{
				goal++;

				y_x.push_back(y);
				y_x.push_back(x);

				character(y * 3 + 10, x * 6 + 10);
			}
		}
	}
	SC.step_w(3, maxx / 3 - 3, 2, 4, 4, step);
	SC.push_w(3, maxx / 3 - 2, 2, maxx / 3 + 1, 4, push);
	SC.level_w(3, maxx / 3 - 2, 2, (maxx / 3) * 2 - 1, 4, level_choice + 1);
	curs_set(0);

	return y_x;


}

vector<vector<int> > map::resetMapArr(vector<vector<int> > mapArr, int Map[5][11][11], int level_choice)
{
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			mapArr[i][j] = Map[level_choice][i][j];
		}
	}
	return mapArr;
}

vector<int> map::condControl(vector<vector<int> > mapArr, vector<int> front)
{
	vector<int> stateChange;
	int chFront = mapArr[front[0]][front[1]];
	int chFront2 = mapArr[front[2]][front[3]];
	if (chFront == 0) // case that the front is tile
	{
		stateChange.push_back(0);  // change to tile
		stateChange.push_back(5);  // change to character
		step++;
	}
	else if (chFront == 3) // case that the front is target
	{
		stateChange.push_back(0);
		stateChange.push_back(15);  // character on the target
		step++;
	}
	else if ((chFront == 2) && (chFront2 == 3))  // case that the front is box and front2 is target
	{
		stateChange.push_back(0);
		stateChange.push_back(5);
		stateChange.push_back(12);  // box on the target
		step++;
		push++;
	}
	else if ((chFront == 2) && (chFront2 == 0)) // case that the front is box and front2 is tile
	{
		stateChange.push_back(0);
		stateChange.push_back(5);
		stateChange.push_back(2);  // change to box
		step++;
		push++;
	}
	else if ((chFront == 12) && (chFront2 == 0)) // case that the front is character on the box and front2 is tile
	{
		stateChange.push_back(0);
		stateChange.push_back(15);
		stateChange.push_back(2);
		step++;
		push++;
	}
	else if ((chFront == 12) && (chFront2 == 3)) // case that the front is character on the box and front2 is target
	{
		stateChange.push_back(0);
		stateChange.push_back(15);
		stateChange.push_back(12);
		step++;
		push++;
	}
	return stateChange;
}

vector<vector<int> > map::wayControl(vector<vector<int> > mapArr, int key, int c_y, int c_x)
{
	vector<int> front;
	vector<int> stateChange;

	switch (key) {
	case KEY_LEFT:
		front.push_back(c_y);
		front.push_back(c_x - 1);
		front.push_back(c_y);
		front.push_back(c_x - 2);
		stateChange = condControl(mapArr, front);
		for (int i = 0; i < stateChange.size(); i++) {
			if (mapArr[c_y][c_x] == 15) { mapArr[c_y][c_x] = 3; }
			else if (mapArr[c_y][c_x] == 12) { mapArr[c_y][c_x] = 3; }
			else { mapArr[c_y][c_x - i] = stateChange[i]; }
		}
		break;
	case KEY_RIGHT:
		front.push_back(c_y);
		front.push_back(c_x + 1);
		front.push_back(c_y);
		front.push_back(c_x + 2);
		stateChange = condControl(mapArr, front);
		for (int i = 0; i < stateChange.size(); i++) {
			if (mapArr[c_y][c_x] == 15) { mapArr[c_y][c_x] = 3; }
			else if (mapArr[c_y][c_x] == 12) { mapArr[c_y][c_x] = 3; }
			else { mapArr[c_y][c_x + i] = stateChange[i]; }
		}
		break;
	case KEY_UP:
		front.push_back(c_y - 1);
		front.push_back(c_x);
		front.push_back(c_y - 2);
		front.push_back(c_x);
		stateChange = condControl(mapArr, front);
		for (int i = 0; i < stateChange.size(); i++) {
			if (mapArr[c_y][c_x] == 15) { mapArr[c_y][c_x] = 3; }
			else if (mapArr[c_y][c_x] == 12) { mapArr[c_y][c_x] = 3; }
			else { mapArr[c_y - i][c_x] = stateChange[i]; }
		}
		break;
	case KEY_DOWN:
		front.push_back(c_y + 1);
		front.push_back(c_x);
		front.push_back(c_y + 2);
		front.push_back(c_x);
		stateChange = condControl(mapArr, front);
		for (int i = 0; i < stateChange.size(); i++) {
			if (mapArr[c_y][c_x] == 15) { mapArr[c_y][c_x] = 3; }
			else if (mapArr[c_y][c_x] == 12) { mapArr[c_y][c_x] = 3; }
			else { mapArr[c_y + i][c_x] = stateChange[i]; }
		}
		break;
	}
	return mapArr;
}
