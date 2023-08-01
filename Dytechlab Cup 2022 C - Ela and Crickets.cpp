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
int moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}};
pp center(){
  int a,b;
  if (x[1]==x[2]) a=x[1];
  else a=x[3];
  
  if (y[1]==y[2]) b=y[1];
  else b=y[3];
  
  return make_pair(a,b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,t,r,c;
  cin>>t;
  while (t--){
    cin>>n;
    for (int i=1;i<=3;i++) cin>>x[i]>>y[i];
    cin>>r>>c;
    
    pp central=center();
    int cx=central.first, cy=central.second;
    // cout<<cx<<" "<<cy<<"\n";
    if ((cx==1 or cx==n) and (cy==1 or cy==n)){
      if (cx==r or cy==c) cout<<"YES\n";
      else cout<<"NO\n";
    }else{
      if ((cx+cy)%2==(r+c)%2){
        if (cx%2==r%2) cout<<"YES\n";
        else cout<<"NO\n";
      }else{
        cout<<"YES\n";
      }
    }
  }
  return 0;
}
