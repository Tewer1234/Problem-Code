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
int used[SIZE];
int pre[SIZE];
vector <int> v;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    used[ary[i]]++;
  }
  
  for (int i=1;i<=n;i++){
    if (!used[i]) v.pb(i);
    else if (used[i]>=2) pre[i]=1;
  }
  
  // for (int i=0;i<v.size();i++) cout<<v[i]<<" ";
  // cout<<"\n";
  
  int cnt=0,ans=0;
  for (int i=1;i<=n;i++){
    if (used[ary[i]]>=2){
      if (ary[i]>v[cnt] or !pre[ary[i]]){
        used[ary[i]]--;
        ary[i]=v[cnt];
        cnt++;
        ans++;
      }else pre[ary[i]]=0;
    }
  }
  
  
  cout<<ans<<"\n";
  for (int i=1;i<=n;i++) cout<<ary[i]<<" ";
  return 0;
}
