// 숫자로 삼각형 출력하기 //

#include <iostream>
using namespace std;

void TriangleNumber(int k);

int main(void){
  int t,k;
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> k;
    TriangleNumber(k);
  }
  return 0;
}

void TriangleNumber(int k){
  int col = 0;
  int plus = 0;

  for(int i=1;i<=k;i++){
    cout << i << " ";
    col = i;
    for(int j=1;j<i;j++){
      col += plus-1;
      cout << col << " ";
      plus--;
    }
    plus = k;
    cout << endl;
  }
}
