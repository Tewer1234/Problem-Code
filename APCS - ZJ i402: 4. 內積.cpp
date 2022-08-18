#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#define ll long long int 
#define pb push_back
using namespace std;
typedef pair<int,int> pp;
int dp[1005][1005];
int check[1005][1005];
int ary[10000],bry[10000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,ans=INT_MIN;
  cin>>n>>m;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
  }
  for (int j=1;j<=m;j++){
    cin>>bry[j];
  }
  for (int i=1;i<=m;i++){
    dp[1][i]=ary[1]*bry[i];
  }
  for (int i=2;i<=n;i++){
    dp[i][1]=ary[i]*bry[1];
    for (int j=2;j<=m;j++){
      // dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
      dp[i][j]=max(dp[i-1][j-1],0)+ary[i]*bry[j];
    }
  }
  // for (int i=0;i<=n;i++){
  //   for (int j=0;j<=m;j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      ans=max(ans,dp[i][j]);
    }
  }
  // cout<<ans<<"\n\n";
  
  memset(dp,0,sizeof(dp));
  for (int i=m;i>=1;i--) dp[1][i]=ary[1]*bry[i]; 
  for (int i=2;i<=n;i++){
    dp[i][n]=ary[i]*bry[n];
    for (int j=m;j>=1;j--){
      // dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j+1]));
      dp[i][j]=max(dp[i-1][j+1],0)+ary[i]*bry[j];
    }
  }
  
  // for (int i=1;i<=n;i++){
  //   for (int j=1;j<=m;j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      ans=max(ans,dp[i][j]);
    }
  }
  cout<<ans;
  return 0;
}

