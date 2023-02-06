#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int x[SIZE],y[SIZE];
pp ary[SIZE];
int used[SIZE];
int pos[SIZE];
bool comp(pp a,pp b){
  if (a.second==b.second and a.first>b.first) return true;
  else if (a.second<b.second) return true;
  else return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  for (int i=1;i<=n;i++) cin>>x[i];
  for (int i=1;i<=n;i++) cin>>y[i];
  for (int i=1;i<=n;i++){
    ary[i].first=x[i];
    ary[i].second=y[i];
  }
  
  sort(ary+1,ary+n+1,comp);
  // for (int i=1;i<=n;i++){
  //   cout<<ary[i].first<<" "<<ary[i].second<<"\n";
  // }
  
  int ans=0;
  for (int i=1;i<=k;i++) pos[i]=-1;
  for (int i=1;i<=n;i++){
    int l,r,mid,temp=-1;
    l=1,r=k;
    while (l<=r){
      mid=(l+r)/2;
      int check=pos[mid];
      if (check<ary[i].first){
        temp=mid;
        l=mid+1;
      }else r=mid-1;
    }
    
    if (temp!=-1){
      pos[temp]=ary[i].second;
      // for (int j=1;j<=k;j++) cout<<j<<": "<<pos[j]<<"\n";
      // cout<<"\n";
      sort(pos+1,pos+k+1);
      ans++;
    }
  }
  cout<<ans;
  return 0; 
}
