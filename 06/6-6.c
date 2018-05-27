//ニュートン法によるロジスティック成長モデルの平衡点の計算
#include<stdio.h>

int main(){
  int i;
  double x,xx,k;

  //パラメータ設定
  k=100.0;

  //初期値
  x=10.0;

  for(i=0;i<1000;i++){
    xx=x*x/(2*x-k);
    x=xx;
  }

  printf("%f\n",x);

  return 0;
}
