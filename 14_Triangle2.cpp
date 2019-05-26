// 삼각형의 종류 2 //

#include <iostream>
#include <cmath>
using namespace std;

int triangle(double ax, double ay, double bx, double by, double cx, double cy);
int main() {
	int t;
	int ax, ay, bx, by, cx, cy;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> ax >> ay >> bx >> by >> cx >> cy;
		cout << triangle(ax, ay, bx, by, cx, cy) << endl;
	}
	return 0;
}

int triangle(double ax, double ay, double bx, double by, double cx, double cy) {
	double len[3]; // 각 변의 길이
	len[0] = (ax - bx)*(ax - bx) + (ay - by)*(ay - by);
	len[1] = (cx - ax)*(cx - ax) + (cy - ay)*(cy - ay);
	len[2] = (cx - bx)*(cx - bx) + (cy - by)*(cy - by);
//	cout << len[0] << " " << len[1] << " " << len[2] << endl;

	double temp;
	for (int i = 0; i<3; i++) { // 크기 정렬
		for (int j = 0; j<3; j++) {
			if (len[i] < len[j]) {
				temp = len[i];
				len[i] = len[j];
				len[j] = temp;
			}
		}
	}
//	cout << len[0] << " " << len[1] << " " << len[2] << endl;

	if (sqrt(len[0]) + sqrt(len[1]) <= sqrt(len[2])) return 0;
	else if (len[0] + len[1] == len[2]) return 1;
	else if (len[0] + len[1] < len[2]) return 2;
	else return 3;
}
