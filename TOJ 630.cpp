#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#define ll long long int 
#define pb push_back
using namespace std;
typedef pair<int,int> pp;
ll ary[1000000],psum[1000000];
set <int> st;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k, ans=0;
  cin>>n>>k;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    psum[i]=(psum[i-1]+ary[i])%k;
  }
  st.insert(0);
  for (int i=1;i<=n;i++){
    ll res=psum[i];
    auto it = st.lower_bound(psum[i]);
    ans=max(ans,psum[i]);
    if (it!=st.end()){
      res = max(res, (psum[i]-(*it)+k)%k);
      ans = max(ans, res);
    }
    st.insert(psum[i]);
  }
  cout<<ans<<"\n";
  return 0;
}

