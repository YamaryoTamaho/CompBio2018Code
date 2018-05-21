#include<stdio.h>
#include<math.h>
#define N 200

int main(){
  int k;
  double p,T;

  FILE *fp;
  fp=fopen("output_5.csv","w");

  for(k=1;k<=N;k++){
    p=(double)k/(double)N;
    T=-(2*(double)N*(1-p)*log(1-p))/p;
    fprintf(fp,"%f %f\n",p,T);
  }
  return 0;
  fclose(fp);
}
