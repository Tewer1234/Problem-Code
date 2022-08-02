//Using bitmask to store the cities that will be travelled to
//DP[the current city where the man is at][the combination that the man will travel in]
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#define ll long long int 
#define N 17
using namespace std;
typedef pair<int,int> pp;
int x[1000000],y[1000000],z[1000000];
ll dp[1005][(1<<N)];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll dis;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>x[i]>>y[i]>>z[i];
  }
  memset(dp,0x3f3f3f,sizeof(dp));
  dp[0][(1<<0)]=0;
  for (int i=1;i<(1<<n);i++){
    int d=i;
    for (int j=0;j<n;j++){
      if ( (d & (1<<j)) ){
        for (int k=0;k<n;k++){
          if ( (d & (1<<k)) ){
            dis=abs(x[j]-x[k])+abs(y[j]-y[k])+max(0,z[j]-z[k]);
            dp[j][d]=min(dp[j][d],dp[k][d^(1<<j)]+dis);
          }
        }
      }
    }
  }
  
  ll ans=LLONG_MAX;
  for (int i=0;i<n;i++){
    dis=abs(x[i]-x[0])+abs(y[i]-y[0])+max(0,z[0]-z[i]);
    ans=min(ans,dp[i][(1<<n)-1]+dis);
  }
  cout<<ans;
  return 0;
}
