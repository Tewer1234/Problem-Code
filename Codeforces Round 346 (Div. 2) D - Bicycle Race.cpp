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
int x[SIZE],y[SIZE];
int moves[100][100]={{0,1},{1,0},{0,-1},{-1,0}};
int main() {
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
  
  int curx,cury,difx,dify,ans=0,tempdir=0,dir=0;
  for (int i=1;i<n;i++){
    curx=x[i],cury=y[i];
    difx=abs(x[i]-x[i+1]);
    dify=abs(y[i]-y[i+1]);
    
    for (int j=0;j<4;j++){
      int tempx=difx*moves[j][0]+curx;
      int tempy=dify*moves[j][1]+cury;
      if (tempx==x[i+1] and tempy==y[i+1]){
        tempdir=j;
        break;
      }
    }
    // cout<<dir<<" "<<tempdir<<"\n";
    if ((tempdir-dir+4)%4==3) ans++;
    dir=tempdir;
  }
  cout<<ans;
  return 0;
}
