// 구간과 숫자의 포함관계 //

#include <iostream>
using namespace std;

int testInclusion(int a, int b, int m);

int main(void){
  int t;
  int a,b,m;
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> a >> b >> m;
    cout << testInclusion(a,b,m) << endl;
  }
  return 0;
}

int testInclusion(int a, int b, int m){
  int result;
  if(m<a||m>b){
    return 0;
  }else{
    return 1;
  }
