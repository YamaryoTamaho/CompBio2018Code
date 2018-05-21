//サイコロの目の総和が100超える
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int r,M,N,x,i;
  srand(time(NULL));
  M=1;
  N=6;
  x=0; //サイコロの目の総和

  for(i=0;i<100;i++){
    r=rand()%(N-M+1)+M;
    x=x+r;
    if(x>=100){
      printf("%d\n",i);
      break;  //x≧100でステップ数出力してループ脱出
    }
  }
  return 0;
}
