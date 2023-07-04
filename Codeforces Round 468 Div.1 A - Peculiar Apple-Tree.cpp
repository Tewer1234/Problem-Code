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
int depth[SIZE];
vector <int> nodes[SIZE];
int cnt[SIZE];
void dfs(int n){
  int nxt;
  for (int i=0;i<nodes[n].size();i++){
    nxt=nodes[n][i];
    depth[nxt]=depth[n]+1;
    dfs(nxt);
  }
  return;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n,x;
  cin>>n;
  for (int i=2;i<=n;i++){
    cin>>x;
    nodes[x].pb(i);
  }
  
  dfs(1);
  int maxDepth=0;
  for (int i=2;i<=n;i++){
    maxDepth=max(maxDepth,depth[i]);
    cnt[depth[i]]++;
  }
  
  int ans=1;
  for (int i=1;i<=maxDepth;i++){
    ans+=(cnt[i]%2);
  }
  cout<<ans;
  return 0;
}
