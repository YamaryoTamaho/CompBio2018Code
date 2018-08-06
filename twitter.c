#include<stdio.h>
#include<math.h>

int main(){
  double Tw,F,G,Dt,E;
  Dt=90;
  G=85;
  E=70;

  FILE	*fp;
  fp=fopen("twitter.csv","w");

  for(F=1;F<=100;F++){
    Tw=pow(100,(Dt/100))+E*exp(-F/G);

    fprintf(fp,"%f,%f\n",F,Tw);
  }
  return 0;
  fclose(fp);
}
