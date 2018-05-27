#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
  int i;
  double t,dt;
  double x[3];
  double xx[3];
  double a,b;

  double x1,x2,y1,y2,r,N=1.0,s=4.0;
  srand(time(NULL));

  FILE *fp;
  fp=fopen("output_6-4_kadai.csv","w");

  dt=0.0001;
  a=0.0003;
  b=0.7;

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
    //x[1]=xx[1];
    x[2]=xx[2];

    //偶然誤差の計算
    x1=(((double)rand()+1)/((double)RAND_MAX+1))*N;
    x2=(((double)rand()+1)/((double)RAND_MAX+1))*N;

    y1=sqrt(-2*log(x1))*cos(2*M_PI*x2)*s;
    y2=sqrt(-2*log(x1))*sin(2*M_PI*x2)*s;

    r=rand()%2;
    if(r==0){
      x[1]=xx[1]+y1;
    }
    if(r==1){
      x[1]=xx[1]+y2;
    }

    if(i%100==0){
      fprintf(fp,"%f, %f, %f, %f\n",t,x[0],x[1],x[2]);
    }
  }
  fclose(fp);
  return 0;
}
