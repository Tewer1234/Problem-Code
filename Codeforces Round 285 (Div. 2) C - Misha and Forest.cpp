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
int deg[SIZE],s[SIZE];
vector <pp> nodes;
queue <int> qq;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>deg[i]>>s[i];
    if (deg[i]==1){
      qq.push(i);
    }
  }
  
  while (!qq.empty()){
    int cur=qq.front();
    qq.pop();
    if (!deg[cur]) continue;
    
    deg[cur]--;
    int nxt=s[cur];
    s[cur]=0;
    if (nxt<n){
      nodes.pb(make_pair(cur,nxt));
      s[nxt]^=cur;
      deg[nxt]--;
      if (deg[nxt]==1) qq.push(nxt);
    }
  }
  
  cout<<nodes.size()<<"\n";
  for (int i=0;i<nodes.size();i++) cout<<nodes[i].first<<" "<<nodes[i].second<<"\n";
  
  return 0;
}
