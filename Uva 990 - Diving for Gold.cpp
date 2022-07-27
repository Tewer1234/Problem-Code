//Uva 990 - Diving for Gold
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int depth[100000],amount[100000],time1[100000];
int dp[2000],total[2000],check[2000],prevs[2000][2000];
int main() {
  int t,w,n,first=1;
  while (cin>>t>>w){
    memset(dp,0,sizeof(dp));
    memset(total,0,sizeof(total));
    memset(check,0,sizeof(check));
    memset(prevs,0,sizeof(prevs));
    cin>>n;
    for (int i=1;i<=n;i++){
      cin>>depth[i]>>amount[i];
      time1[i]=(w*depth[i])+(2*w*depth[i]);
    }
    if (first) first=0;
    else cout<<"\n";
    check[0]=1;
    for (int i=n;i>=1;i--){
      for (int j=t;j>=0;j--){
        if (j-time1[i]>=0 and check[j-time1[i]]){
          check[j]=1;
          if (dp[j-time1[i]]+amount[i]>=dp[j]){
            dp[j]=dp[j-time1[i]]+amount[i];
            total[j]=total[j-time1[i]]+1;
            prevs[j][i]=1;
          }
        }
      }
    }
    int maxSum=0,cnt=0,num=0;
    for (int i=1;i<=t;i++){
      if (maxSum<dp[i]){
        cnt=total[i];
        num=i;
        maxSum=dp[i];
      }
      // cout<<i<<": "<<dp[i]<<"\n";
    }
    cout<<maxSum<<"\n"<<cnt<<"\n";
    for(int i = 1; i <= n; i++) {
        if (prevs[num][i] == 1) {
            cout<<depth[i]<<" "<<amount[i]<<"\n";
            num -= time1[i];
        }
    }
  }
  return 0;
}
