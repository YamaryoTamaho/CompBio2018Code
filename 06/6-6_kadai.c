#include<stdio.h>

int main(){
  int i;
  double x,xx,dt,t;

  //パラメータ設定
  dt=0.001;

  //初期値
  x=10.0;

  for(i=1;i<1000;i++){
    t=dt*i;
    xx=x-(1/t);
    x=xx;
  }

  printf("%f\n",x);

  return 0;
}
