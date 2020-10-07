// 패리티비트 // 

#include <iostream>
#include <cmath>
using namespace std;

void paritybit(unsigned int n);

int main() {
	int t;
	unsigned int n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		paritybit(n);
	}
	return 0;
}

void paritybit(unsigned int n) {
	unsigned int bit[32];
	int cnt = 0;
	for (int i = 0; i < 32; i++) {
		bit[i] = (n >> i) & 1;   // 10진수 2진수로 변환
		if (bit[i] == 1) cnt++;
	}

	unsigned int ten2two = 0;
	if (cnt % 2 != 0) {
		bit[31] = 1;  // 1의 개수가 홀수인 경우, 마지막 비트 1로 변경

		for (int j = 0; j < 32; j++) {  // 2진수 10진수로 변환
			if (bit[j] == 1)
				ten2two += pow(2, j);
		}
		cout << ten2two << endl;
	}
	else
		cout << n << endl;

}