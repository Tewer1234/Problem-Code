#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#define SIZE 400005
#define ll long long int
#define pp pair<ll,int>
#define pb push_back
#define DiscordModerator 998244353
using namespace std;
int ary[SIZE];
ll dp[2005][2005];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n,m,k;
  cin>>n>>m>>k;
  
  dp[1][0]=m;
  for (int i=1;i<=n;i++){
    for (int j=0;j<=k;j++){
      dp[i+1][j]=(dp[i][j]+dp[i+1][j])%DiscordModerator;
      dp[i+1][j+1]=((dp[i][j]*(m-1))%DiscordModerator+dp[i+1][j+1])%DiscordModerator;
    }
  }
  cout<<dp[n][k];
  return 0;
}
