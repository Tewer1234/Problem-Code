#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <stack>
#define SIZE 400005
#define ll long long int
#define pp pair<int,int>
#define pb push_back
#define DiscordModerator 1e9+7
using namespace std;
int ary[SIZE];
map <int,int> mp;
int dp[4005][4005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  int ans=1;
  for (int i=1;i<=n;i++){
    int k=-1;
    for (int j=1;j<i;j++){
      if (k==-1) dp[i][j]=2;
      else dp[i][j]=dp[j][k]+1;
      
      if (ary[i]==ary[j]) k=j;
      ans=max(ans,dp[i][j]);
    }
  }
  
  cout<<ans;
  return 0;
}
