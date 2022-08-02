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
int ary[10000000];
int psum[10000000];
vector <int> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,pos=0;
  ll temp,len;
  cin>>n;
  v.pb(0);
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    if (ary[i]) v.pb(ary[i]);
  }
  for (int i=1;i<v.size();i++){
    psum[i]=psum[i-1]+v[i];
  }
  len=v.size()-1;
  temp=0;
  for (int i=1;i<=len;i++){
    if (psum[i]<temp){
      temp=psum[i];
      pos=i;
    }
  }
  // cout<<"\n";
  ll ans=0,cur=1;
  pos++;
  // cout<<temp<<" "<<pos<<"\n";
  for (int i=1;i<=n;i++){
    if (pos!=i){
      // cout<<i<<": "<<v[cur]<<"\n";
      ans+=(i*v[cur]);
      cur++;
    }
  }
  cout<<ans;
  return 0;
}
