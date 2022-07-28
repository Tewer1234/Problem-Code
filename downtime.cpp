#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <queue>
#define ll long long int 
using namespace std;
typedef pair<int,int> pp;
int ary[1000000],used[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  ll ans=1,cnt=0;
  cin>>n>>k;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    used[ary[i]]++;
    if (ary[i]<1000) cnt++;
  }
  ll temp=ans*k;
  while (temp<cnt){
    // cout<<temp<<" "<<cnt<<"\n";
    ans++;
    temp=ans*k;
  }
  // cout<<ans<<"\n";
  for (int i=1000;i<=110000;i++){
    if (used[i-1000]){
      cnt-=used[i-1000];
    }
    cnt+=used[i];
    temp=ans*k;
    while (temp<cnt){
      ans++;
      temp=ans*k;
    }
    // cout<<i<<" "<<ans<<" "<<cnt<<"\n";
  }
  cout<<ans;
  return 0;
}
