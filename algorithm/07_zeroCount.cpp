// 끝자리 0의 개수 구하기 //

#include <iostream>
using namespace std;

int zeroCount(int n);

int main(void) {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << zeroCount(n) << endl;
	}
	return 0;
}


int zeroCount(int n) {
	int m;
	int two = 0;
	int five = 0;
	for (int i = 0; i < n; i++) {
		cin >> m;
		int m2 = m;
		while (m2 % 2 == 0) {
			two++;
			m2 = m2 / 2;
		}
		int m5 = m;
		while (m5 % 5 == 0) {
			five++;
			m5 = m5 / 5;
		}
	}
	if (two > five)
		return five;
	else
		return two;
}
