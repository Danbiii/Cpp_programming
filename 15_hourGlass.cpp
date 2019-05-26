// 모래시계 출력하기 //

#include <iostream>
using namespace std;

void hourglass(int n);

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		hourglass(n);
	}
	return 0;
}

void hourglass(int n){
	int row, col, minus;
	int half = n / 2;
	// 위
	for (row = 0; row < half+1; row++) {
		for (minus = 0; minus < row; minus++)
			cout << "-";
		for (col = 0; col < (n-2*row); col++) {
			if (col % 2 == 0)
				cout << "*";
			else
				cout << "+";
		}
		for (minus = 0; minus < row; minus++)
			cout << "-";
		cout << endl;
	}

	// 아래
	for (row = half-1; row >= 0; row--) {
		for (minus = 0; minus < row; minus++)
			cout << "-";
		for (col = 0; col < (n - 2 * row); col++) {
			if (col % 2 == 0)
				cout << "*";
			else
				cout << "+";
		}
		for (minus = 0; minus < row; minus++)
			cout << "-";
		cout << endl;
	}


}
