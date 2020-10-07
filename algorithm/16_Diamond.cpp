// 다이아몬드 출력하기 //

#include <iostream>
using namespace std;

void diamond(int n);

int main() {
	int t,n;
	cin >> t;
	for (int i=0; i < t; i++) {
		cin >> n;
		diamond(n);
	}
	return 0;
}

void diamond(int n) {
	int half = n / 2;
	int col, row, plus;
	// 위
	for(row=0;row<half;row++){
		for(col = half; col > row; col--) // 왼쪽 *
			cout << "*";
		for(plus = 0; plus < row * 2+1; plus++) // 중간 +
			cout << "+";
		for (col = half; col > row; col--) // 오른쪽 *
			cout << "*";
		cout << endl;
	}
	// 가운데
	for (int plus = 0; plus < n; plus++)
		cout << "+";
	cout << endl;
	// 아래
	for (row = half-1; row >= 0; row--) {
		for (col = half; col > row; col--)
			cout << "*";
		for (plus = 0; plus < row * 2 + 1; plus++)
			cout << "+";
		for (col = half; col > row; col--)
			cout << "*";
		cout << endl;
	}
}
