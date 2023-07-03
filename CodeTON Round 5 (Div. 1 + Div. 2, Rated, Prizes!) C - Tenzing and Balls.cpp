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
int dp[SIZE];
int least[SIZE];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n,t;
  cin>>t;
  while (t--){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>ary[i];
    memset(dp,0,sizeof(dp));
    memset(least,0x3f3f3f,sizeof(least));
    
    dp[0]=0;
    for (int i=1;i<=n;i++){
      dp[i]=min(dp[i-1]+1,least[ary[i]]);
      least[ary[i]]=min(least[ary[i]],dp[i-1]);
    }
    
    cout<<n-dp[n]<<"\n";
  }
  return 0;
}
