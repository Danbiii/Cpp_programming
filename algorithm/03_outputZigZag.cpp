// 숫자 지그재그 출력하기 //

#include <iostream>
using namespace std;

void outputZigZag(int n, int k);

int main(void){
  int t;
  int n,k;

  cin >> t;
  for(int i=0;i<t;i++){
    cin >> n >> k;
    outputZigZag(n,k);
  }
  return 0;
}


void outputZigZag(int n, int k){
  int first=0;
  if(k==1){
    cout << 1 << endl;
  }else if(k%2==0){
    for(int i=1;i<=k;i++){
      first += i;
    }
    cout << first; // first number
    for(int j=1;j<k;j++){
      cout<<"*"<<first-j;
    }
    cout << endl;
  }else{
    for(int i=1;i<k;i++){
      first += i;
    }
    cout << first+1;
    for(int j=1;j<k;j++){
      cout << "*" << first+1+j;
    }
    cout << endl;
  }
}
