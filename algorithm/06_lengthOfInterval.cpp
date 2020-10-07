// 두 구간의 겹쳐진 길이 //

#include <iostream>
using namespace std;

int LengthOfInterval(int a, int b, int c, int d);

int main() {
	int t;
	int a, b, c, d;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c >> d;
		cout << LengthOfInterval(a, b, c, d) << endl;
	}
	return 0;
}

int LengthOfInterval(int a, int b, int c, int d) {
	int result;
	if (a <= b && b < c && c <= d) result = -1;
	else if (a <= b && b == c && c <= d) result = 0;
	else if (a <= c && c <= d && d <= b) result = d - c;
	else if (a <= c && c <= b && b <= d) result = b - c;
	else if (c <= d && d < a && a <= b) result = -1;
	else if (c <= d && d == a && a <= b) result = 0;
	else if (c <= a && a <= b && b <= d) result = b - a;
	else if (c <= a && a <= d && d <= b) result = d - a;

	return result;
}
