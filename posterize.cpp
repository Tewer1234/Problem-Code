//Rule for DP: From pixel i~j (i<=n and j<=n), the minimum square sum error when choosing m numbers of the k numbers.
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#define ll long long int 
using namespace std;
typedef pair<ll,ll> pp;
ll dp[1005][1005],psum[1005][1005];
pp red[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,d;
  ll total=0,temp;
  memset(dp,0x3f3f3f3f,sizeof(dp));
  cin>>n>>d;
  for (int i=1;i<=n;i++){
    cin>>red[i].first>>red[i].second;
  }
  for (int i=1;i<=n;i++){
    for (int j=i;j<=n;j++){
      psum[i][j]=LLONG_MAX;
    }
  }
  for (int i=0;i<256;i++){
    for (int j=1;j<=n;j++){
      temp=0;
      for (int k=j;k<=n;k++){
        temp=temp+(red[k].first-i)*(red[k].first-i)*red[k].second;
        psum[j][k]=min(psum[j][k],temp);
      }
    }
    // for (int j=1;j<=n;j++){
    //   cout<<j<<": \n";
    //   for (int k=j;k<=n;k++){
    //     cout<<psum[j][k]<<"\n";
    //   }
    // }
    // cout<<"\n";
  }
  dp[0][0]=0;
  // for (int i=1;i<=n;i++){
  //   for (int j=i;j<=n;j++){
  //     cout<<i<<" "<<j<<": "<<psum[i][j]<<"\n";
  //   }
  // }
  // cout<<"----------------\n";
  for (int i=1;i<=n;i++){
    for (int j=1;j<=d;j++){
      for (int k=0;k<i;k++){
        dp[i][j]=min(dp[i][j],dp[k][j-1]+psum[k+1][i]);
      }
    }
  }
  cout<<dp[n][d];
  // for (int i=1;i<=n;i++){
  //   for (int j=1;j<=d;j++){
  //     cout<<i<<" "<<j<<": "<<dp[i][j]<<"\n";
  //   }
  // }
  return 0;
}
