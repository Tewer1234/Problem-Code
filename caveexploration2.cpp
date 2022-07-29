#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <queue>
#define ll long long int 
using namespace std;
struct node{
  int x,y,level;
};
typedef pair<int,node> pp;
int ary[1005][1005];
int moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}};
ll ans,dist[1005][1005];
struct comp{
  bool operator()(pp a,pp b){
    // ll disa=dist[a.x][a.y],disb=dist[b.x][b.y];
    // if (disa<=disb) return true;
    // else return false;
    return a.first<b.first;
  }
};
void dijk(int n){
  ll temp;
  node t;
  priority_queue <pp,vector <pp>, comp > pq;
  t.x=t.y=t.level=1;
  pq.push(make_pair(dist[1][1],t));
  while (!pq.empty()){
    node cur=pq.top().second;
    pq.pop();
    for (int i=0;i<4;i++){
      node nxt=cur;
      nxt.x+=moves[i][0],nxt.y+=moves[i][1];
      if ((nxt.x>=1 and nxt.x<=n) and (nxt.y>=1 and nxt.y<=n)){
        temp=0;
        if (ary[nxt.x][nxt.y]>=cur.level){
          temp=ary[nxt.x][nxt.y]-cur.level+1;
          nxt.level=ary[nxt.x][nxt.y]+1;
        }
        if (dist[nxt.x][nxt.y]>dist[cur.x][cur.y]+temp){
          dist[nxt.x][nxt.y]=dist[cur.x][cur.y]+temp;
          pq.push(make_pair(dist[nxt.x][nxt.y],nxt));
        }
      }
    }
  }
  cout<<dist[n][n];
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      cin>>ary[i][j];
    }
  }
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      dist[i][j]=LLONG_MAX;
    }
  }
  dist[1][1]=0;
  dijk(n);
  return 0;
}
