#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#define ll long long int 
#define pb push_back
using namespace std;
typedef pair<int,int> pp;
struct node{
  int x,y,s,t;
};
node ary[1000];
int used[1000],bombs[1000][1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r,c,n;
  cin>>r>>c>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i].x>>ary[i].y>>ary[i].s>>ary[i].t;
  }
  int flag=1;
  while (flag){
    
    // for (int i=0;i<r;i++){
    //   for (int j=0;j<c;j++){
    //     cout<<bombs[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    int tempx,tempy,left=0;
    for (int i=1;i<=n;i++){
      if (!used[i]){
        left=1;
        break;
      }
    }
    if (!left){
      flag=0;
      break;
    }
    
    
    for (int i=1;i<=n;i++){
      if (!used[i] and !bombs[ary[i].x][ary[i].y]){
        bombs[ary[i].x][ary[i].y]++;
      }
    }
    for (int i=1;i<=n;i++){
      tempx=ary[i].x+ary[i].s,tempy=ary[i].y+ary[i].t;
      if (!used[i]){
        if (tempx<0 or tempx>=r or tempy<0 or tempy>=c){
          used[i]=1;
        }else{
          ary[i].x=tempx;
          ary[i].y=tempy;
        }
      }
    }
    for (int i=1;i<=n;i++){
      int explode=0;
      if (!used[i] and bombs[ary[i].x][ary[i].y]){
        for (int j=1;j<=n;j++){
          if (!used[j] and ary[i].x==ary[j].x and ary[i].y==ary[j].y){
            used[j]=1;
            explode=1;
          }
        }
        if (explode) bombs[ary[i].x][ary[i].y]=0;
      }
    }
    // for (int i=0;i<r;i++){
    //   for (int j=0;j<c;j++){
    //     cout<<bombs[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
  }
  int ans=0;
  for (int i=0;i<r;i++){
    for (int j=0;j<c;j++){
      if (bombs[i][j]) ans++;
    }
  }
  cout<<ans;
  return 0;
}
