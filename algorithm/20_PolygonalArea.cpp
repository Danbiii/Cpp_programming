// 다각형 면적 // 

#include <iostream>
#include <cmath>
using namespace std;

void polygonalArea(int n);
int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		polygonalArea(n);
	}
	return 0;
}

void polygonalArea(int n) {
	int size = 2 * (n + 1);
	int *polygon = new int[size];
	int i;
	for (i = 0; i < size - 2; i++) {
		cin >> polygon[i];
	}
	polygon[i] = polygon[0];
	polygon[i + 1] = polygon[1];

	double signedArea = 0;
	for (int i = 0; i <= 2 * (n - 1); i += 2) {
		signedArea += (polygon[i] + polygon[i + 2])*(polygon[i + 3] - polygon[i + 1]);
	}
	signedArea = 0.5*signedArea;
	double area = 2 * abs(signedArea);
	cout << area << " ";

	if (signedArea < 0) cout << -1 << endl;
	else if (signedArea > 0) cout << 1 << endl;
	delete[] polygon;
}