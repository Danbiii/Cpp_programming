// �и�Ƽ��Ʈ // 

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
		bit[i] = (n >> i) & 1;   // 10���� 2������ ��ȯ
		if (bit[i] == 1) cnt++;
	}

	unsigned int ten2two = 0;
	if (cnt % 2 != 0) {
		bit[31] = 1;  // 1�� ������ Ȧ���� ���, ������ ��Ʈ 1�� ����

		for (int j = 0; j < 32; j++) {  // 2���� 10������ ��ȯ
			if (bit[j] == 1)
				ten2two += pow(2, j);
		}
		cout << ten2two << endl;
	}
	else
		cout << n << endl;

}