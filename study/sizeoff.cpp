#include <iostream>
#include <climits>

using namespace std;

int main(){
	short year = SHRT_MAX;
	int sale = INT_MAX;
	long total_sale = LONG_MAX;

	cout << "size of short: " << sizeof(short) << endl;
	cout << "size of int: " << sizeof(int) << endl;
	cout << "size of long: " << sizeof(long) << endl;

	cout << "max of short: " << year << endl;
	cout << "max of int: " << sale << endl;
	cout << "max of long: " << total_sale << endl;

	cout << "min of short: " << SHRT_MIN << endl;
	cout << "min of int: " << INT_MIN << endl;
	cout << "min of long: " << LONG_MIN << endl;

	return 0;
}
