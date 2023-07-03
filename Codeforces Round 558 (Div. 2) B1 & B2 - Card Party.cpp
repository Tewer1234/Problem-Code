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
int cnt[SIZE];
map <int,int> mp;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n,ans=1,check=1;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  for (int i=1;i<=n;i++){
    if (cnt[ary[i]]){
      mp[cnt[ary[i]]]--;
      if (!mp[cnt[ary[i]]]) mp.erase(cnt[ary[i]]);
    }
    cnt[ary[i]]++;
    mp[cnt[ary[i]]]++;
    
    if (mp.size()==2){
      check=0;
      auto it=mp.find(1);
      if (it!=mp.end() and mp[1]==1){
        ans=i;
      }else{
        int first=1;
        int temp1,temp2;
        for (auto it:mp){
          if (first){
            first=0;
            temp1=it.first;
          }else temp2=it.first;
        }
        
        if (temp1+1==temp2){
          if (mp[temp2]==1){
            ans=i;
          }
        }
      }
    }
    
    // cout<<i<<": \n";
    // for (auto it:mp){
    //   cout<<it.first<<": "<<it.second<<"\n";
    // }
  }
  
  if (check and mp.size()==1){
    for (auto it:mp) ans=max(it.first,it.second);
  }
  cout<<ans;
  return 0;
}
