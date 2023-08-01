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
int cnt[SIZE];
int used[SIZE];
int each[SIZE];
int check[SIZE];
map <int,int> mp;
vector <int> nodes[SIZE];
vector <int> a,b;
vector <pp> rem;
bool comp(pp a,pp b){
  return a.first<b.first;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,maxd=0;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    nodes[ary[i]].pb(i);
    mp[ary[i]]++;
    maxd=max(maxd,ary[i]);
  }
  
  for (auto it:mp){
    if (it.second>=2) each[it.first]=it.second/2;
  }
  
  int pos;
  for (int i=1;i<=n;i++){
    if (each[ary[i]]>=1 and !check[ary[i]]){
      for (int j=0;j<each[ary[i]];j++){
        pos=nodes[ary[i]][cnt[ary[i]]];
        a.pb(pos);
        cnt[ary[i]]++;
        mp[ary[i]]--;
        used[pos]=1;
      }
      
      for (int j=0;j<each[ary[i]];j++){
        pos=nodes[ary[i]][cnt[ary[i]]];
        b.pb(pos);
        cnt[ary[i]]++;
        mp[ary[i]]--;
        used[pos]=1;
      }
      if (!mp[ary[i]]) mp.erase(ary[i]);
      check[ary[i]]=1;
    }
  }
  
  for (int i=1;i<=n;i++){
    if (!used[i]) rem.pb(make_pair(ary[i],i));
  }
  sort(rem.begin(),rem.end(),comp);
  // cout<<a.size()<<" "<<b.size()<<"\n";
  
  for (int i=0;i<rem.size();i++){
    if (a.size()<b.size()) a.pb(rem[i].second);
    else b.pb(rem[i].second);
  }
  
  cout<<a.size()<<"\n";
  for (int i=0;i<a.size();i++) cout<<a[i]<<" ";
  cout<<"\n"<<b.size()<<"\n";
  for (int i=0;i<b.size();i++) cout<<b[i]<<" ";
  return 0;
}
