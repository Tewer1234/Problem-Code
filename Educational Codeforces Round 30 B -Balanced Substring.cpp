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
#define pb push_back()
using namespace std;
int cnt0[SIZE];
int cnt1[SIZE];
int ans[SIZE];
map <int,int> mp;
int main() {
  int n,dif;
  string s;
  cin>>n>>s;
  
  s=" "+s;
  for (int i=1;i<s.size();i++){
    if (s[i]=='0') cnt0[i]=cnt0[i-1]+1,cnt1[i]=cnt1[i-1];
    else cnt1[i]=cnt1[i-1]+1,cnt0[i]=cnt0[i-1];
  }
  for (int i=1;i<s.size();i++){
    dif=cnt1[i]-cnt0[i];
    auto it1=mp.find(dif);
    if (it1==mp.end()) mp[dif]=i;
  }
  
  
  // for (auto it:mp) cout<<it.first<<" "<<it.second<<"\n";
  // for (int i=1;i<s.size();i++) cout<<i<<": "<<cnt1[i]-cnt0[i]<<"\n";
  // cout<<"\n";
  
  ans[mp[0]]=mp[0];
  for (int i=1;i<s.size();i++){
    int temp,pos;
    dif=cnt1[i]-cnt0[i];
    pos=mp[dif];
    temp=i-pos+ans[pos];
    ans[i]=temp;
  }
  
  int tt=0;
  for (int i=1;i<s.size();i++){
    tt=max(tt,ans[i]);
  }
  cout<<tt;
  return 0;
}
