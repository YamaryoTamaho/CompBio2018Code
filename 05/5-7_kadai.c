#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 200
#define k 181

int main(){
  int a[N],aa[N],i,t,r1,r2,r,sum,tsum=0,count=0;
  double p,ave;
  srand(time(NULL));

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
        sum=sum+a[i];
      }
      if(sum==N){
        count++;
        tsum=tsum+(t+1);
        //printf("%d\n",t+1);
        break;
      }
    }
  }
  p=(double)k/(double)N;
  ave=(double)tsum/(double)count;
  printf("k=%d N=%d p=%.3f\n%d %d\nT=%.3f\n",k,N,p,count,tsum,ave);
  return 0;
}
