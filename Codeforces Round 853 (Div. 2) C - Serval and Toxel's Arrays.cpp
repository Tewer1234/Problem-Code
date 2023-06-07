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
int check[SIZE];
int cnt[SIZE];
int main() {
  int n,t,m,pos,val;
  ll ans;
  cin>>t;
  while (t--){
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>ary[i];
    
    memset(check,-1,sizeof(check));
    memset(cnt,0,sizeof(cnt));
    ans=0;
    for (int i=1;i<=n;i++){
      check[ary[i]]=0;
    }
    
    for (int i=1;i<=m;i++){
      cin>>pos>>val;
      cnt[ary[pos]]+=(i-check[ary[pos]]);
      check[ary[pos]]=-1;
      
      if (check[val]==-1) check[val]=i;
      ary[pos]=val;
    }
    
    for (int i=1;i<=n+m;i++){
      if (check[i]!=-1){
        cnt[i]+=(m+1-check[i]);
      }
    }
    
    ll total=(ll)m*(m+1)/2;
    for (int i=1;i<=n+m;i++){
      ans+=(total-((ll)(m-cnt[i])*(m-cnt[i]+1)/2));
    }
    cout<<ans<<"\n";
  }
  return 0;
}
