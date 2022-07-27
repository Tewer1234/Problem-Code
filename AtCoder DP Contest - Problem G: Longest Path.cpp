//AtCoder DP Contest - Problem G: Longest Path
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#define ll long long int 
using namespace std;
int dis[1000000],used[1000000],check[1000000],len[1000000],dg[1000000],ans;
vector <int> nodes[1000000];
vector <int> qq;
void bfs(int temp){
  int cur,nxt;
  for (int i=0,j=temp;i<j;i++){
    cur=qq[i];
    for (int k=0;k<len[cur];k++){
      nxt=nodes[cur][k];
      dis[nxt]=max(dis[nxt],dis[cur]+1);
      dg[nxt]--;
      if (!dg[nxt]){
        qq.push_back(nxt);
        j++;
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,x,y,temp=0;
  cin>>n>>m;
  for (int i=1;i<=m;i++){
    cin>>x>>y;
    nodes[x].push_back(y);
    len[x]++;
    dg[y]++;
    check[y]=1;
  }
  for (int i=1;i<=n;i++){
    if (!check[i]){
      qq.push_back(i);
      temp++;
    }
  }
  bfs(temp);
  for (int i=1;i<=n;i++){
    ans=max(ans,dis[i]);
  }
  cout<<ans;
  return 0;
}
