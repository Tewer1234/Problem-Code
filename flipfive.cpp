#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#define ll long long int 
using namespace std;
typedef pair<int,int> pp;
int moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}};
string ary[1000];
struct node{
  char grid[10][10];
  int clicks;
};
node qq[10000000];
int bfs(){
  int flag=1,tempx,tempy;
  node cur,nxt;
  char c;
  string t="";
  map <string,int> mp;
  for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
      qq[0].grid[i][j]='.';
      t+='.';
    }
  }
  qq[0].clicks=0;
  mp[t]++;
  for (int i=0,j=1;i<j;i++){
    cur=qq[i];
    flag=1;
    for (int k=0;k<3;k++){
      for (int l=0;l<3;l++){
        if (cur.grid[k][l]!=ary[k][l]){
          flag=0;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) return cur.clicks;
    else{
      for (int k=0;k<3;k++){
        for (int l=0;l<3;l++){
          
          t="";
          nxt=cur;
          c=nxt.grid[k][l];
          if (c=='.') c='*';
          else c='.';
          nxt.grid[k][l]=c;
          for (int dir=0;dir<4;dir++){
            tempx=k,tempy=l;
            tempx+=moves[dir][0];
            tempy+=moves[dir][1];
            if ((tempx>=0 and tempx<3) and (tempy>=0 and tempy<3)){
              c=nxt.grid[tempx][tempy];
              if (c=='.') c='*';
              else c='.';
              nxt.grid[tempx][tempy]=c;
            }
          }
          for (int row=0;row<3;row++){
            for (int col=0;col<3;col++){
              t+=nxt.grid[row][col];
            }
          }
          // cout<<t<<"\n";
          auto it=mp.find(t);
          if (it==mp.end()){
            // cout<<t<<"\n";
            int cnt=2;
            // for (int k=0;k<t.size();k++){
            //   cout<<t[k];
            //   if (k==cnt) cout<<"\n",cnt+=3;
            // }
            // cout<<"\n";
            mp[t]++;
            nxt.clicks++;
            qq[j]=nxt;
            j++;
          }
        }
      }
    }
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string t;
  cin>>n;
  while (n--){
    for (int i=0;i<3;i++){
      cin>>ary[i];
    }
    // for (int i=0;i<3;i++){
    //   cout<<ary[i]<<"\n";
    // }
    // cout<<"\n";
    cout<<bfs()<<"\n";
  }
  return 0;
}
