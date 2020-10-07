// 1차원 라이프 게임 //

#include <iostream>
using namespace std;
void lifegame(int *life, int n, int k);

int main() {
	int t,n,k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;

		int *life = new int[n];
		for(int j=0;j<n;j++)
			cin >> life[j];

		lifegame(life, n, k);

		for(int l=0;l<n;l++)
			cout << life[l] << " ";
		cout << endl;
		delete[] life;
	}

	return 0;
}

void lifegame(int *life, int n, int k) {
	for(int time = 0;time<k;time++){
		int *next_life = new int[n];
		// cout << "copy" << endl;
		for(int i=0;i<n;i++){
			next_life[i] = life[i]; // 기존의 값으로 초기화
		}
		//맨 앞
		if(life[1] <3 ||life[1] >7){
			if(life[0] != 0) next_life[0]--; // 소멸
		}
		else if (life[1]>3 && life[1]<=7){
			if(life[0] < 9) next_life[0]++; // 생성
		}

		//맨 뒤
		if(life[n-2] <3 ||life[n-2] >7){
			if(life[n-1] != 0) next_life[n-1]--; // 소멸
		}
		else if (life[n-2]>3 && life[n-2]<=7){
			if(life[n-1] < 9) next_life[n-1]++; // 생성
		}
		// 중간
		for(int cell=1;cell<n-1;cell++){
			int side = life[cell-1] + life[cell+1];
			if(side <3 ||side >7){
				if(life[cell] != 0) next_life[cell]--; // 소멸
			}
			else if (side > 3 && side<=7){
				if(life[cell] < 9) next_life[cell]++; // 생성
			}
		}

		for(int k=0;k<n;k++){
			life[k] = next_life[k];
		}
		delete[] next_life;
	}
}
