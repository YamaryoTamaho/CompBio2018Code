#include<stdio.h>
int main(void){
  int t=0;
  double k=100.0,r=1.0,x1,x2;

  FILE *fp;
  fp=fopen("output.dat","w");

  for(r=1.0;r<3.0;r+=0.1){
    fprintf(fp,"r=%.1f\n",r);

    x1=10.0;
    for(t=0;t<50;t++){
    x2=x1+r*(1.0-x1/k)*x1;
    fprintf(fp,"%d,%.3f\n",t,x2);
    x1=x2;
    }
  }
  fclose(fp);
  return 0;
}
