//Uva 10130 - SuperSale
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int p[1000000],w[1000000],c[1000000];
int dp[1000][1000],check[1000][1000];
int main() {
  int n,it,people;
  cin>>n;
  while (n--){
    memset(dp,0,sizeof(dp));
    memset(check,0,sizeof(check));
    cin>>it;
    for (int i=1;i<=it;i++){
      cin>>p[i]>>w[i];
    }
    cin>>people;
    for (int i=1;i<=people;i++){
      cin>>c[i];
    }
    for (int j=1;j<=people;j++){
      check[j][c[j]]=1;
    }
    for (int j=1;j<=people;j++){
      check[j][0]=1;
    }
    
    for (int i=1;i<=it;i++){
      for (int j=1;j<=people;j++){
        for (int k=c[j];k>=0;k--){
          if (k-w[i]>=0 and check[j][k-w[i]]){
            check[j][k]=1;
            dp[j][k]=max(dp[j][k],dp[j][k-w[i]]+p[i]);
          }
        }
      }
    }
    int maxSum,ans=0;
    for (int i=1;i<=people;i++){
      maxSum=0;
      for (int j=0;j<=c[i];j++){
        maxSum=max(maxSum,dp[i][j]);
        // cout<<dp[i][j]<<" ";
      }
      ans+=maxSum;
      // cout<<"\n";
    }
    cout<<ans<<"\n";
    // cout<<"\n";
  }
  return 0;
}
