// 숫자 피라미드 출력하기 //

#include <iostream>
using namespace std;

void outputPyramid(int n, int k);

int main(void) {
	int t;
	int n, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		outputPyramid(n, k);
	}
	return 0;
}

void outputPyramid(int n, int k) {
	int aa = 0;
	cout << k;
	for (int a = n - 1; a > n - k; a--) {
		aa += a;
		cout << "*" << k + aa;
	}
	cout << endl;
}
