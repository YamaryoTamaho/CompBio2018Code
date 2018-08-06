#include <stdio.h>
#include <math.h>
int main(){
  int i,j;
  double a,A,b,c,dh,dr,m,n,P,t,T,dt,Th,xmax_th,xmax_ex,alpha,beta,gamma,sa,sb,sg,s2,score,x[3],xx[3];
  //ファイルを開く
  FILE *fp;
  fp=fopen("allergy_ode.csv","w");

  //患者のおかれる条件にあたるパラメータ
  a=2.0; A=10.0; b=10.0; c=0.9; dh=0.05; dr=0.01; m=0.045; n=20.0; T=9000.0;

  //アレルギー発症の閾値
  Th=50.0;

  //スコアリング関連
  //閾値とヘルパーT細胞数のピークの差
  xmax_th=0;
  xmax_ex=0;
  //スコアの要素
  score=0;
  alpha=0;
  beta=0;
  gamma=0;

  //Th数が大きいときスコアを頭打ちにする
  sa=0.2;
  sb=0.1;
  sg=0.15;
  s2=-0.1;
  dt=0.1;

  //治療なし(j=0)、治療あり(j=1)それぞれ計算
  for(j=0;j<2;j++){
    //初期化
    xmax_th=0;
    xmax_ex=0;
    x[0]=0;
    x[1]=0;
    for(i=0;i<12000;i++){
      t=dt*i;
      //花粉の摂取量Pに値を代入
      //花粉飛散期に入る前
      if(i<=T){
        //治療なしの場合は0
        if(j==0){
          P=0;
        }
        //治療ありの場合は少量(a)ずつ投与
        else{
          P=a;
        }
      }
      //花粉飛散期
      else{
        P=A;
      }

      //モデル
      xx[0]=x[0]+dt*(P*b*(1-c)-dr*x[0]);
      xx[1]=x[1]+dt*(P*b*c/(1+m*(x[0]+n))-dh*x[1]);
      x[0]=xx[0];
      x[1]=xx[1];
      //Th数のピークの値を記録
      //花粉飛散前のTh数のピーク
      if(i<=T){
        if(x[1]>xmax_th){
          xmax_th=x[1];
        }
      }
      //花粉飛散期のTh数のピーク
      else{
        if(x[1]>xmax_ex){
          xmax_ex=x[1];
        }
      }
      fprintf(fp,"%f,%f,%f,%f\n",t,x[1],xmax_th,xmax_ex);
    }
    //ここまでで花粉飛散期までの計算終わり

    //スコアの要素alpha, beta, gammaを計算
    if(j==1){
      if(xmax_th>Th){
        beta=-pow((xmax_th-Th),sb);
      }
      else{
        beta=-pow((Th-xmax_th),s2);
      }
    }
    if(xmax_ex>Th){
      if(j==0){
        alpha=pow((xmax_ex-Th),sa);
      }
      else{
        gamma=-pow((xmax_ex-Th),sg);
      }
    }
    else{
      if(j==0){
        alpha=pow((Th-xmax_ex),s2);
      }
      else{
        gamma=-pow((Th-xmax_ex),s2);
      }
    }
  }
  //ここまでで治療なし・あり(j=0, 1)両方の計算が終了
  //スコア算出
  score=alpha+beta+gamma;

  //画面上に表示
  printf("alpha=%f,beta=%f,gamma=%f,score=%f\n",alpha,beta,gamma,score);
  fclose(fp);
  return 0;
}