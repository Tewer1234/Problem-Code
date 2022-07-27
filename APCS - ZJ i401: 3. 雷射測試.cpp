//APCS - i401: 3. 雷射測試
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long int
using namespace std;
struct node{
  int t,val;
};
node d1;
vector <node> x[30005],y[60005];
int slash[100][100]={{1,0,3,2},{3,2,1,0}};
bool comp(node a,node b){
  return a.val<b.val;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,l,r,c,curx,cury,dir=1;
  ll ans=0;
  curx=cury=0;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>l>>r>>c;
    d1.t=c;
    d1.val=r;
    // cout<<d1.t<<" "<<d1.val<<"\n";
    x[l].push_back(d1);
    d1.val=l;
    if (r<0){
      y[30000-r].push_back(d1);
    }else{
      y[r].push_back(d1);
    }
  }
  for (int i=0;i<=30000;i++){
    sort(x[i].begin(),x[i].end(),comp);
  }
  for (int i=0;i<=60000;i++){
    if (y[i].size()) sort(y[i].begin(),y[i].end(),comp);
  }
  int flag=1;
  while (flag){
    int l,r,mid,temp=-1,tempy;
    if (dir==0 or dir==2){
      l=0,r=x[curx].size()-1;
      // cout<<l<<"gh "<<r<<"\n";
      // for (int j=0;j<=r;j++) cout<<x[curx][j].val<<" ";
      // cout<<"\n";
      while (l<=r){
        mid=(l+r)/2;
        if (dir==0){
          if (x[curx][mid].val>cury){
            temp=mid;
            r=mid-1;
          }else{
            l=mid+1;
          }
        }else{
          if (x[curx][mid].val<cury){
            temp=mid;
            l=mid+1;
          }else{
            r=mid-1;
          }
        }
      }
    }else{
      if (cury<0) tempy=30000-cury;
      else tempy=cury;
      l=0,r=y[tempy].size()-1;
      // cout<<l<<"gh "<<r<<"\n";
      // for (int j=0;j<=r;j++) cout<<y[tempy][j].val<<" ";
      // cout<<"\n";
      while (l<=r){
        mid=(l+r)/2;
        // if (cury<0) tempy=cury+30001+abs(cury);
        if (dir==1){
          if (y[tempy][mid].val>curx){
            temp=mid;
            r=mid-1;
          }else{
            l=mid+1;
          }
        }else{
          if (y[tempy][mid].val<curx){
            temp=mid;
            l=mid+1;
          }else{
            r=mid-1;
          }
        }
      }
    }
    // cout<<temp<<"\n";
    if (temp>=0){
      ans++;
      if (dir==0 or dir==2){
        dir=slash[x[curx][temp].t][dir];
        cury=x[curx][temp].val;
      }else{
        // cout<<dir<<"\n";
        dir=slash[y[tempy][temp].t][dir];
        curx=y[tempy][temp].val;
      }
      // cout<<curx<<' '<<cury<<" "<<dir<<"\n";
    }else{
      flag=0;
      break;
    }
  }
  cout<<ans;
  return 0;
}
