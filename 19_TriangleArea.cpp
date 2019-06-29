// 삼각형 면적 // 

#include <iostream>
#include <cmath>
using namespace std;

void TriangleArea(int ax, int ay, int bx, int by, int cx, int cy);
int main() {
	int t;
	int ax, ay, bx, by, cx, cy;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> ax >> ay >> bx >> by >> cx >> cy;
		TriangleArea(ax, ay, bx, by, cx, cy);
	}
	return 0;
}

void TriangleArea(int ax, int ay, int bx, int by, int cx, int cy) {
	double signedArea = 0.5*((bx - ax)*(cy - ay) - (cx - ax)*(by - ay));
	double area = 2 * abs(signedArea);
	cout << area << " ";
	if (signedArea > 0) cout << 1 << endl;
	else if (signedArea < 0) cout << -1 << endl;
	else cout << 0 << endl;
}