#include <iostream>
#include <climits>

using namespace std;

int main(){
	short s_money = SHRT_MAX; //최대값으로 초기화
	unsigned short u_money = USHRT_MAX; //최대값으초 초기화

	s_money = s_money + 1; // overflow 발생 = -32768
	cout << "s_money = " << s_money << endl;
	
	u_money = u_money + 1; // overflow 발생 = 0
	cout << "u_money = " << u_money << endl;

	return 0;
}
