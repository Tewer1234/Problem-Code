//Uva 10066 - The Twin Towers
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int t1[1000000],t2[1000000];
int dp[1000][1000],moves[100][100]={{0,-1},{-1,-1},{-1,0}};
int main() {
  int n,m,cases=0;
  while (cin>>n>>m){
    memset(dp,0,sizeof(dp));
    if (!n and !m) break;
    for (int i=1;i<=n;i++){
      cin>>t1[i];
    }
    for (int i=1;i<=m;i++){
      cin>>t2[i];
    }
    for (int i=1;i<=n;i++){
      for (int j=1;j<=m;j++){
        int posx,posy,tempx,tempy;
        for (int k=0;k<3;k++){
          tempx=i+moves[k][0],tempy=j+moves[k][1];
          if (!k){
            posx=tempx;
            posy=tempy;
          }else{
            if (dp[posx][posy]<dp[tempx][tempy]){
              posx=tempx;
              posy=tempy;
            }
          }
        }
        if (t1[i]==t2[j]){
          dp[i][j]=dp[i-1][j-1]+1;
        }else{
          // cout<<tempx<<" "<<tempy<<"\n";
          dp[i][j]=dp[posx][posy];
        }
      }
    }
    // for (int i=1;i<=n;i++){
    //   for (int j=1;j<=m;j++){
    //     cout<<dp[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    cases++;
    cout<<"Twin Towers #"<<cases<<"\n";
    cout<<"Number of Tiles : "<<dp[n][m]<<"\n\n";
  }
  return 0;
}
