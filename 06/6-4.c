#include<stdio.h>
int main(){
  int i;
  double t,dt;
  double x[3];
  double xx[3];
  double a,b;

  FILE *fp;
  fp=fopen("output_6-4.csv","w");

  dt=0.0001;
  a=0.001;
  b=0.01;

  t=0.0;
  x[0]=10000;
  x[1]=100;
  x[2]=0;

  fprintf(fp,"%f,%f,%f,%f\n",t,x[0],x[1],x[2]);

  for(i=1;i<=100000;i++){
    t=dt*i;
    xx[0]=x[0]+dt*(-a*x[0]*x[1]);
    xx[1]=x[1]+dt*(a*x[0]*x[1]-b*x[1]);
    xx[2]=x[2]+dt*(b*x[1]);
    x[0]=xx[0];
    x[1]=xx[1];
    x[2]=xx[2];

    if(i%100==0){
      fprintf(fp,"%f, %f, %f,%f\n",t,x[0],x[1],x[2]);
    }
  }
  fclose(fp);
  return 0;
}
