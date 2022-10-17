#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int ary[55][10005];
int dp[55][10005];
int tdp[55][10005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r,n;
  cin>>r>>n;
  for (int i=1;i<=r;i++){
    for (int j=1;j<=n;j++){
      cin>>ary[i][j];
    }
  }
  
  memset(dp,0x80,sizeof(dp));
  for (int i=1;i<=n;i++) dp[0][i]=0;
  for (int i=1;i<=r;i++){
    int mval;
    //left
    for (int j=1;j<=n;j++){
      mval=max(dp[i][j],dp[i-1][j]+ary[i][j]);
      dp[i][j]=mval;
      if (j+1<=n){
        dp[i][j+1]=max(dp[i][j+1],mval+ary[i][j+1]);
      }
    }
    
    //right
    for (int j=n;j>=1;j--){
      mval=max(tdp[i][j],dp[i-1][j]+ary[i][j]);
      tdp[i][j]=mval;
      if (j-1>=1){
        tdp[i][j-1]=max(tdp[i][j-1],mval+ary[i][j-1]);
      }
    }
    
    for (int j=1;j<=n;j++) dp[i][j]=max(dp[i][j],tdp[i][j]);
    
    // for (int j=1;j<=n;j++){
    //   cout<<dp[i][j]<<" ";
    // }
    // cout<<"\n";
  }
  
  int ans=INT_MIN;
  for (int i=1;i<=n;i++){
    ans=max(ans,dp[r][i]);
  }
  cout<<ans;
  return 0; 
}
