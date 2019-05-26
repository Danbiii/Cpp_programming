// 1월 1일의 요일 계산하기 //

#include <iostream>
using namespace std;

int January(int y);

int main() {
	int t;
	int y,year;
	int result;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int week[7] = { 0,1,2,3,4,5,6 };
		cin >> y;
		year = y - 1;
		result = (year * 365 + year / 4 - year / 100 + year / 400 + 1) % 7;
		cout << week[result] << endl;
	}
	return 0;
}
