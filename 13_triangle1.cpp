// 삼각형의 종류 1 //

#include <iostream>
using namespace std;

int triangle1(int a, int b, int c);

int main(){
  int t,a,b,c;
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> a >> b >> c;
    cout << triangle1(a,b,c) << endl;
  }
  return 0;
}

int triangle1(int a, int b, int c){
  int result;
  if(a+b<=c) result = 0;
  else if(a==b && b==c && a==c) result = 1;
  else if(a*a+b*b==c*c) result = 2;
  else if(a==b || b==c || c==a) result = 3;
  else result = 4;

  return result;
}
