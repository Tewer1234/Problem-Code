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
map <int,pp> mp;
vector <pp> seg;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  int first=1,l,r;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    
    auto it=mp.find(ary[i]);
    if (it==mp.end()) mp[ary[i]].first=i;
    
    mp[ary[i]].second++;
    if (mp[ary[i]].second==2){
      if (first){
        l=mp[ary[i]].first;
        r=i;
        first=0;
      }else if (mp[ary[i]].first>r){
        l=mp[ary[i]].first;
        r=i;
      }
      
      seg.pb(make_pair(l,r));
      mp.clear();
    }
  }
  
  if (!seg.size()) cout<<-1;
  else{
    cout<<seg.size()<<"\n";
    if (seg.size()==1) cout<<1<<" "<<n<<"\n";
    else{
      for (int i=0;i<seg.size();i++){
        if (i<seg.size()-1){
          if (i==0) cout<<1<<" "; 
          else cout<<seg[i].first<<" ";
          cout<<seg[i+1].first-1<<"\n";
        }else{
          cout<<seg[i].first<<" "<<n;
        }
      }
    }
  }
  return 0;
}
