// 수직 수평 성분의 교차 //

#include <iostream>
using namespace std;
#define SZ 4
int crossline(int first[SZ], int second[SZ]);

int main() {
	int t;
	int first[SZ], second[SZ];
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < SZ; j++) cin >> first[j];
		for (int j = 0; j < SZ; j++) cin >> second[j];

		cout << crossline(first, second) << endl;
	}
	return 0;
}

int crossline(int first[SZ], int second[SZ]) {
	int xy[8];
	// first 수직 & second 수평 >> xy = {first, second}
	if (first[0] == first[2]) {
		int temp;
		if (first[1] > first[3]) {
			temp = first[1];
			first[1] = first[3];
			first[3] = temp;
		} // first(x1, y1) < first(x2, y2)
		if (second[0] > second[2]) {
			temp = second[0];
			second[0] = second[2];
			second[2] = temp;
		} // second(x1, y1) < second(x2, y2)
		for (int i = 0; i < SZ; i++) {
			xy[i] = first[i];
		}
		for (int i = SZ; i < 8; i++) {
			xy[i] = second[i - SZ];
		}
	}
	// first 수평 & second 수직 >> xy = {second, first}
	else {
		int temp;
		if (second[1] > second[3]) {
			temp = second[1];
			second[1] = second[3];
			second[3] = temp;
		} // first(x1, y1) < first(x2, y2)
		if (first[0] > first[2]) {
			temp = first[0];
			first[0] = first[2];
			first[2] = temp;
		} // second(x1, y1) < second(x2, y2)
		for (int i = 0; i < SZ; i++) {
			xy[i] = second[i];
		}
		for (int i = SZ; i < 8; i++) {
			xy[i] = first[i - SZ];
		}
	}
	// 수직 x가 수평 x 사이에 존재
	if (xy[4] <= xy[0] && xy[0] <= xy[6]) {
		// 수평 y가 수직 y 사이에 존재
		if (xy[1] <= xy[5] && xy[5] <= xy[3]) {
			// 끝과 끝이 닿을 때 (접할 때)
			if ((xy[1] == xy[5]) || (xy[3] == xy[5]) || (xy[0] == xy[4]) || xy[0] == xy[6])
				return 2;
			else
				return 1; // 교차
		}
		else
			return 0; // 위 아래로 그어져서 만나지 않음
	}
	else
		return 0; // 선분 교차 사각형에 속하지 않아서 만나지 않음
}
