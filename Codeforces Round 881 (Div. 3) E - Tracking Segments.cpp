#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#define SIZE 400005
#define ll long long int
#define pp pair<ll,int>
#define pb push_back
#define DiscordModerator 998244353
using namespace std;
int ary[SIZE];
int l[SIZE],r[SIZE];
int presum[SIZE];
bool check(int mid,int n,int m){
  int length,dif;
  memset(presum,0,sizeof(presum));
  for (int i=1;i<=mid;i++) presum[ary[i]]=1;
  for (int i=1;i<=n;i++) presum[i]+=presum[i-1];
  for (int i=1;i<=m;i++){
    dif=presum[r[i]]-presum[l[i]-1];
    length=(r[i]-l[i]+1)-dif;
    // cout<<mid<<": "<<l[i]<<" "<<r[i]<<": "<<dif<<" "<<length<<"\n";
    if (dif>length) return true;
  }
  return false;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int t,n,m,q;
  cin>>t;
  while (t--){
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
    cin>>q;
    for (int i=1;i<=q;i++) cin>>ary[i];
    
    int l=1,r=q,mid,ans=-1;
    while (l<=r){
      mid=((l+r)>>1);
      if (check(mid,n,m)){
        ans=mid;
        r=mid-1;
      }else l=mid+1;
    }
    cout<<ans<<"\n";
  }
  return 0;
}
