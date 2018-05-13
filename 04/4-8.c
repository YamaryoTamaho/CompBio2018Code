#include<stdio.h>
int main(){
  int i,j;
  double  t,dt;
  double x[2];
  double xx[2];
  double a,b,c,d,e,f;

  FILE *fp;
  fp=fopen("output_4-8.csv","w");

  dt=0.0001;
  a=4.0;
  b=2.0;
  c=1.0;
  d=5.0;
  e=1.0;
  f=3.0;

  t=0.0;
  x[0]=0.4;
  x[1]=0.4;
  fprintf(fp,"%f,%f,%f\n",t,x[0],x[1]);

  for(i=0;i<=100000;i++){
    t=dt*i;
    xx[0]=x[0]+dt*(a-b*x[0]+c*x[1])*x[0];
    xx[1]=x[1]+dt*(d+e*x[0]-f*x[1])*x[1];
    x[0]=xx[0];
    x[1]=xx[1];

    if(i%100==0){
      fprintf(fp,"%f,%f,%f\n",t,x[0],x[1]);
    }
  }
  fclose(fp);
  return 0;
}
