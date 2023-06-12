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
#define pp pair<ll,int>
#define pb push_back
using namespace std;
int ary[SIZE];
int tt[SIZE];
int main() {
  int n,k;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  memset(tt,0x3f3f3f,sizeof(tt));
  int l,r,mid;
  tt[0]=-1;
  for (int i=1;i<=n;i++){
    l=0,r=i;
    k=-1;
    while (l<=r){
      mid=((l+r)>>1);
      if (tt[mid]<ary[i]){
        k=mid+1;
        l=mid+1;
      }else r=mid-1;
    }
    
    if (k!=-1) tt[k]=ary[i];
  }
  
  // for (int i=1;i<=n;i++) cout<<i<<": "<<tt[i]<<"\n";
  
  int ans=0;
  for (int i=1;i<=n;i++){
    l=1,r=n;
    k=-1;
    while (l<=r){
      mid=((l+r)>>1);
      if (tt[mid]>ary[i]) r=mid-1;
      else{
        k=mid;
        l=mid+1;
      }
    }
    
    if (k!=-1){
      ans=max(ans,k);
    }
  }
  cout<<ans;
  return 0;
}
