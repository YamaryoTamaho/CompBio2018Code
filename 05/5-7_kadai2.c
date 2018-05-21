#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
#define k 90

int main(){
  int a[N],aa[N],i,t,r1,r2,r,sum,tsum=0,count=0;
  double ave;
  srand(time(NULL));

 //for(k=5;k<=N;k+=10){
  while(count<100){
    for(i=0;i<N;i++){
      if(i<k){
        a[i]=1;
      }
      else{
        a[i]=0;
      }
    }
    for(t=0;t<1000;t++){
      sum=0;
      for(i=0;i<N;i++){
        r1=rand()%N;
        r2=rand()%N;
        r=rand()%2;
        if(r==0){
          aa[i]=a[r1];
        }
        if(r==1){
          aa[i]=a[r2];
        }
      }
      for(i=0;i<N;i++){
        a[i]=aa[i];
      }
      for(i=0;i<N;i++){
        sum=sum+a[i];
      }
      if(sum==N){
        count++;
        tsum=tsum+(t+1);
        //printf("%d\n",t+1);
        break;
      }
    }
    if(count>=100){
      break;
    }
  }
  ave=(double)tsum/(double)count;
  printf("%d %d %.3f\n",count,tsum,ave);
 //}
  return 0;
}
