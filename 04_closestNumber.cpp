// 가장 가까운 수 구하기 //

#include <iostream>
#include <cmath>
using namespace std;

int closestNumber(int n, int m);

int main(void)
{
	int t;
	int n, m;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << closestNumber(n, m) << endl;
	}
	return 0;
}

int closestNumber(int n, int m) {
	int a, result;

	if (n%m == 5){
		a = abs(n / m) + 1;
	}
	else {
		a = round((float) n / m);
	}
	result = m * a;
	return result;
}
