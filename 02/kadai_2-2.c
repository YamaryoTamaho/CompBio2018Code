#include<stdio.h>
int main(void){
  int t=0;
  double k=100.0,r=1.0,x1,x2;

  FILE *fp;
  fp=fopen("output.dat","w");

  for(r=1.0;r<3.0;r+=0.001){

    x1=10.0;
    for(t=0;t<300;t++){
    x2=x1+r*(1.0-x1/k)*x1;
    if(250<=t){
      fprintf(fp,"%.3f %.3f\n",r,x2);
    }
    x1=x2;
    }
  }
  fclose(fp);
  return 0;
}
