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
int ary[1000005],l[1000005],ans[1000005];
int dp[25][1000005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,p,require=1;
  map <int,int> mp;
  cin>>n>>p;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
  }
  l[0]=1;
  for (int i=1;i<=n;i++){
    l[i]=max(l[i-1],mp[ary[i]]+1);
    mp[ary[i]]=i;
    // cout<<l[i]<<" ";
    // ans[i]=(i-l[i]+1);
  }
  // cout<<"\n";
  //k = 1
  
  // int m=0;
  // for (int i=1;i<=n;i++){
  //   m=max(m,ans[i]);
  // }
  // cout<<m;
  
  //k > 1
  
  for (int i=1;i<=p;i++){
    for (int j=1;j<=n;j++){
      // cout<<(l[j-1]==l[j])<<dp[i-1][l[j]-1]<<" "<<j-l[j]+1<<" ";
      dp[i][j]=max(dp[i][j],dp[i][j-1]);
      dp[i][j]=max(dp[i][j],dp[i-1][l[j]-1]+(j-l[j]+1));
      // cout<<"dp ["<<i<<"]["<<j<<"] = "<<dp[i][j]<<"\n";
    }
  }
  int bb=0;
  for (int i=1;i<=n;i++){
    bb=max(bb,dp[p][i]);
  }
  cout<<bb;
  return 0;
}

