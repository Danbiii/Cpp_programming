#pragma once
#include "screen.h"
#include <vector>

class map
{
public:
	// window image generate
	void character(int _y, int _x);
	void target(int _y, int _x);
	void tile(int _y, int _x);
	void box(int _y, int _x);
	void wall(int _y, int _x);
	void blank(int _y, int _x);

	// map
	vector<int> mapshow(vector<vector<int> > mapArr, int maxx, int step, int push, int level_choice);
	vector<vector<int> > resetMapArr(vector<vector<int> > mapArr, int Map[5][11][11], int level_choice);

	// character move
	vector<int> condControl(vector<vector<int> > mapArr, vector<int> front);
	vector<vector<int> > wayControl(vector<vector<int> > mapArr, int key, int c_y, int c_x);
};
