// 시침과 분침사이 각 구하기 //

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int angleClock(int h, int m);

int main(void){
  int t,h,m;
  cin >> t;

  for(int i=0;i<t;i++){
    cin >> h >> m;
    cout << angleClock(h,m) <<endl;
  }
  return 0;
}

int angleClock(int h, int m){
  // 한시간에 30도, 1분당 5.5도
  float hours,minutes,angle;

  hours = h*30;
  minutes = m*5.5;
  angle = abs(hours - minutes);
  if(angle>180)
    angle = floor(360-angle);

  return angle;
}
