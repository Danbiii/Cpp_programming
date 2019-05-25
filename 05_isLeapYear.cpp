// 윤년 계산하기 //

#include <iostream>
using namespace std;

int IsLeapYear(int year);

int main(void) {
	int t;
	int year;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> year;
		cout << IsLeapYear(year) << endl;
	}
	return 0;
}

int IsLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	return 0;
}
