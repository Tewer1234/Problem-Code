//Uva 10285 - Longest Run on a Snowboard
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int grid[1000][1000];
int dp[1000][1000];
int moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}},ans;
struct node{
  int x, y,val;
};
node qq[100000000];
void bfs (int sx,int sy,int r,int c){
  node cur,next;
  qq[0].x=sx;
  qq[0].y=sy;
  qq[0].val=1;
  for (int i=0,j=1;i<j;i++){
    cur=qq[i];
    ans=max(ans,cur.val);
    for (int k=0;k<4;k++){
      next=cur;
      next.x+=moves[k][0];
      next.y+=moves[k][1];
      next.val++;
      if ((next.x>=1 and next.x<=r) and (next.y>=1 and next.y<=c)){
        if (grid[cur.x][cur.y]>grid[next.x][next.y]){
          qq[j]=next;
          j++;
        }
      }
    }
  }
}
int main() {
  int n,r,c;
  string name;
  cin>>n;
  while (n--){
    int tempx,tempy;
    memset(dp,0,sizeof(dp));
    cin>>name>>r>>c;
    for (int i=1;i<=r;i++){
      for (int j=1;j<=c;j++){
        cin>>grid[i][j];
      }
    }
    ans=0;
    for (int i=1;i<=r;i++){
      for (int j=1;j<=c;j++){
        bfs(i,j,r,c);
      }
    }
    cout<<name<<": "<<ans<<"\n";
  }
  return 0;
}
