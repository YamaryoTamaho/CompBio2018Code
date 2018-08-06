#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int i,j,count,sum=0,r;
  double ave;

//  FILE *fp;
//  fp=fopen("twitter2.csv","w");
//  fprintf(fp,"")

  srand(time(NULL));
  for(i=0;i<10;i++){
    count=0;
    for(j=0;j<100;j++){
      r=rand()%100;
      if(r<70){
        count++;
//        printf("%d ",r);
      }
    }
//    printf("\n");
  //  sum=sum+count;
  //  printf("\n%d ",count);
  sum=sum+count;
//  printf("%d\n",sum);
  }

  ave=(double)sum/10.0;
  printf("%f",ave);

  return 0;
}
