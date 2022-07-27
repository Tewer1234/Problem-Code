//c463: apcs 樹狀圖分析 (Tree Analyses)
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct data{
  int val;
  int depth=0;
};
int dis[100005];
int root[100005],used[100005];
bool check[100005];
data d;
vector <int> nodes[100005];
vector <data> qq;
void bfs(){
  data cur,next;
  for (int i=0,j=qq.size();i<qq.size();i++){
    cur=qq[i];
    next.val=root[cur.val];
    if (next.val>=1){
      // cout<<cur.val<<": "<<next.val<<"\n";
      next.depth=cur.depth;
      next.depth=max(next.depth+1,dis[next.val]);
      dis[next.val]=next.depth;
      used[next.val]--;
      if (!used[next.val]){
        // cout<<cur.val<<": "<<next.val<<"\n";
        qq.push_back(next);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll ans=0;
  int n,m,num;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>m;
    for (int j=1;j<=m;j++){
      cin>>num;
      check[num]=true;
      nodes[i].push_back(num);
      root[num]=i;
    }
  }
  int r;
  for (int i=1;i<=n;i++){
    if (!check[i]){
      r=i;
      break;
    }
  }
  for (int i=1;i<=n;i++){
    used[i]=nodes[i].size();
    if (!nodes[i].size()){
      d.val=i;
      d.depth=0;
      used[i]=true;
      qq.push_back(d);
    }
  }
  bfs();
  for (int i=1;i<=n;i++){
    ans+=dis[i];
    // cout<<i<<": "<<dis[i]<<"\n";
  }
  cout<<r<<"\n"<<ans;
  return 0;
}
Collapse




